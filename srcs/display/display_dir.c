/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:15:42 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/26 14:34:19 by abiestro         ###   ########.fr       */
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
	if (pass)
		ft_strcpy(new_pass, pass);
	ft_strcat(new_pass, "/");
	if (current)
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
	new_dir->d_name = name;
	if (lstat(new_pass, &info))
		return NULL;
	ft_copy_stat_info_to_ls_dir(new_dir, &info);
	return (new_dir);
}

int calc_nbr_element_in_a_row(int colums, int definite_size, char *str)
{
	(void)str;
	return (colums / (definite_size + 3));
}

void				ft_display_dir(t_ls *ls, t_ls_dir *current_dir)
{
	DIR				*dir;
	struct dirent	*i;
	t_ls_dir		*new;
	char			*new_pass;
	size_t			max_size;
	int				nbr_elem;

	new_pass = NULL;
	max_size = 0;
	dir = opendir(current_dir->name);
	if (!dir)
		return;
	ft_printf("%s :\n", current_dir->name);
	while ((i = readdir(dir)))
	{
		if (*i->d_name == '.')
			continue;
		if ((new = ft_read_next_entry(current_dir->name, i->d_name)))
		{
			new->level = current_dir->level + 1;
			max_size = (ft_strlen(new->d_name) > max_size) ? ft_strlen(new->d_name) : max_size;
			ft_insert_inchain_list(&ls->elements, new, test_fn);
		}
	}
	closedir(dir);

	nbr_elem = calc_nbr_element_in_a_row(ls->term_width, max_size, new->d_name);
	int k = 1;
	while ((new = ls->elements) && ls->elements->level)
	{
		
		if (ls->option & OPTION_l)
			display_l(new);
		else if (new->name && *new->name)
		{
			ft_printf("%s", new->d_name);
			write(1, LOOOONG_SPACE, max_size - ft_strlen(new->d_name) + 3);
		}
		if (!(k % nbr_elem))
			ft_printf(("\n"));
		ls->elements = ls->elements->next;
		k++;
	}
	ft_printf("\n");
}
