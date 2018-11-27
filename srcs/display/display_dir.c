/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:15:42 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/27 16:32:02 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "errno.h"
#include <sys/types.h>
#include <dirent.h>

static char			*ft_add_pass_to_name(t_ls_dir *element, char *pass,
		char *current)
{
	char *new_pass;

	new_pass = NULL;
	if (!current || !pass || !*current || !*pass)
		return (NULL);
	if (!(new_pass = malloc(sizeof(char) *
					(ft_strlen(pass) + ft_strlen(current) + 2))))
		return (NULL);
	new_pass[0] = 0;
	ft_strcpy(new_pass, pass);
	ft_strcat(new_pass, "/");
	ft_strcat(new_pass, current);
	if (element)
		element->name = new_pass;
	return (new_pass);
}

static t_ls_dir		*ft_read_next_entry(char *pass, char *name)
{
	t_ls_dir		*new_dir;
	char			*new_pass;
	struct stat		info;
	

	new_pass = NULL;
	new_dir = NULL;
	new_pass = ft_add_pass_to_name(NULL, pass, name);
	if (!new_pass)
		return (NULL);
	if (!(new_dir = ft_new_ls_dir(new_pass, 0)))
		return (NULL);
	if (!(new_dir->d_name = ft_strdup(name)))
		return (NULL);
	if (lstat(new_pass, &info))
		new_dir->valid = errno;
	else
		ft_copy_stat_info_to_ls_dir(new_dir, &info);
	return (new_dir);
}

int calc_nbr_element_in_a_row(int colums, int definite_size)
{
	return (colums / (definite_size));
}

void				ft_display_dir(t_ls *ls, t_ls_dir *current_dir)
{
	DIR				*dir;
	struct dirent	*i;
	t_ls_dir		*new;
	char			*new_pass;
	size_t			max_size;
	int				nbr_elem;
	t_ls_dir		*saved;

	new_pass = NULL;
	max_size = 1;
	saved = NULL;
	new = NULL;
	dir = opendir(current_dir->name);
	if (!dir)
		return;
	ft_printf("%s :\n", current_dir->name);
	if (current_dir->valid)
		ft_printf("coucou ./ft_ls : %s : %s\n", current_dir->name, strerror(current_dir->valid));
	while ((i = readdir(dir)))
	{
		if (ft_strequ(i->d_name,".") || ft_strequ(i->d_name,"..") || ft_strstr(i->d_name, "/.") || *i->d_name == '.')
			continue;
		if ((new = ft_read_next_entry(current_dir->name, i->d_name)))
		{
			new->level = current_dir->level + 1;
			new->type = LS_DIR;
			max_size = (ft_strlen(new->d_name) > max_size) ? ft_strlen(new->d_name) : max_size;
			ft_insert_inchain_list(ls, &saved, new, test_fn);
		}
	}
	closedir(dir);
	nbr_elem = calc_nbr_element_in_a_row(ls->term_width, max_size);
	int k = 1;
	while ((new = saved))
	{
		saved = saved->next;
		new->next = NULL;
		if (ls->option & OPTION_l)
			display_l(new);
		else
		{
			ft_display_files(ls, new);
			write(1, LOOOONG_SPACE, max_size - ft_strlen(new->d_name));
		}
		if (!(OPTION_l & ls->option) && !(k % nbr_elem - 1))
			ft_printf(("\n"));
		if (ls->option & OPTION_R && (S_ISDIR(new->stats.st_mode)) && !S_ISLNK(new->stats.st_mode))
			ft_insert_inchain_list(ls, &ls->elements, new, test_fn);
		else
			ft_del_ls_dir(&new);
		k++;
	}
	if (max_size != 1)
		ft_printf("\n");
}
