/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_save_dir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:03:57 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/26 14:40:26 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/types.h>
#include <dirent.h>

static char			*ft_add_pass_to_name(t_ls_dir *element, char *pass, char *current)
{
	char *new_pass;

	new_pass = NULL;
	if (!current || !pass || !*current || !*pass )
		return (NULL);
	if (!(new_pass = malloc(sizeof(char) * (ft_strlen(pass) + ft_strlen(current) + 2))))
		return (NULL);
	ft_strcpy(new_pass, pass);
	ft_strcat(new_pass, "/");
	ft_strcat(new_pass, current);
	if (element)
		element->name = new_pass;
	return (new_pass);
}

int					ft_read_and_save_dir(t_ls *ls, t_ls_dir *current_dir)
{
	DIR             *dir;
	struct dirent   *i;
	struct stat     info;
	int             returned;
	t_ls_dir        *new;
	char            *new_str;

	dir = opendir(current_dir->name);
	if (!dir)
		return (0);
	ft_printf("\n%s :\n", current_dir->name);
	while ((i = readdir(dir)))
	{
		if (ft_strequ(i->d_name,".") || ft_strequ(i->d_name,"..") || ft_strstr(i->d_name, "/.") || *i->d_name == '.')
			continue;
		new_str = ft_add_pass_to_name(NULL, current_dir->name, i->d_name); 
		if (!new_str)
			continue;
		returned = lstat((new_str), &info);
		new = ft_new_ls_dir(new_str, 0);
		ft_copy_stat_info_to_ls_dir(new, &info);
		new->level = current_dir->level + 1;
		if (returned)
			return (1);
		if(S_ISLNK(new->stats.st_mode))
			continue;
		if (ls->option & OPTION_l)
			display_l(new);
		else
			ft_printf("%s ", i->d_name);
		if (returned)
		{
			new->valid = 0;
			new->type = BAD_ELEMENT;
			ft_insert_inchain_list(&ls->elements, new, test_fn);
		}
		else
		{
			new->type = LS_DIR;
			ft_insert_inchain_list(&ls->elements, new, test_fn);            
		}
	}
	closedir(dir);
	ft_printf("\n");
	return (1);
}
