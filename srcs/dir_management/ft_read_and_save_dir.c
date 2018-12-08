/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_save_dir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:03:57 by abiestro          #+#    #+#             */
/*   Updated: 2018/12/08 17:30:41 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/types.h>
#include <dirent.h>
#include "errno.h"

int					ft_handle_hidden(t_ls *ls, t_ls_dir *element, int max_size)
{
	if (!(OPTION_A & ls->option) && *element->d_name == '.')
	{
		return (1);
	}
	if (ft_strequ(element->d_name, ".") || ft_strequ(element->d_name, ".."))
	{
		if (ls->option & OPTION_L)
			display_l(element);
		else
		{
			ft_display_files(ls, element);
			write(1, LOOOONG_SPACE, max_size - ft_strlen(element->d_name));
		}
		return (1);
	}
	return (0);
}

t_ls_dir			*ft_read_dir(t_ls *ls,
		t_ls_dir *current_dir, size_t *max_size)
{
	DIR				*dir;
	struct dirent	*i;
	t_ls_dir		*new;
	t_ls_dir		*saved;

	saved = NULL;
	if (ls->arg_count > 1 || current_dir->level > 0)
		ft_printf("%s :\n", current_dir->name);
	if (!(dir = opendir(current_dir->name)))
	{
		ft_printf("ft_ls : %s : %s\n", current_dir->name, strerror(errno));
		return (NULL);
	}
	while ((i = readdir(dir)))
	{
		if ((new = ft_read_next_entry(current_dir->name, i->d_name)))
		{
			more_info_ls_dir(new, current_dir->level, 3, current_dir->arg);
			*max_size = (ft_strlen(new->d_name) > *max_size) ?
				ft_strlen(new->d_name) : *max_size;
			ft_insert_inchain_list(ls, &saved, new, test_fn);
		}
	}
	closedir(dir);
	return (saved);
}

void				ft_handle_dir(t_ls *ls,
		t_ls_dir *new, int max_size, int modulo)
{
	if (ft_handle_hidden(ls, new, max_size))
	{
		ft_del_ls_dir(&new);
		return ;
	}
	if (ls->option & OPTION_L)
		display_l(new);
	else
	{
		ft_display_files(ls, new);
		write(1, LOOOONG_SPACE, max_size - ft_strlen(new->d_name));
	}
	if (!(OPTION_L & ls->option) && !(modulo))
		ft_printf(("\n"));
	if (ls->option & OPTION_RR && (S_ISDIR(new->stats.st_mode))
			&& !S_ISLNK(new->stats.st_mode))
		ft_insert_inchain_list(ls, &ls->elements, new, test_fn);
	else
		ft_del_ls_dir(&new);
}

void				ft_display_dir(t_ls *ls, t_ls_dir *current_dir)
{
	t_ls_dir	*new;
	size_t		max_size;
	int			nbr_elem;
	t_ls_dir	*saved;
	int			k;

	max_size = 1;
	saved = NULL;
	new = NULL;
	if (!(saved = ft_read_dir(ls, current_dir, &max_size)))
		return ;
	nbr_elem = calc_nbr_element_in_a_row(ls->term_width, max_size + 1);
	k = nbr_elem + 1;
	while ((new = saved))
	{
		saved = saved->next;
		new->next = NULL;
		ft_handle_dir(ls, new, max_size, ((nbr_elem) ? k % nbr_elem : 1));
		k++;
	}
	if (max_size != 1)
		ft_printf("\n");
}
