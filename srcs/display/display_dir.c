/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:15:42 by abiestro          #+#    #+#             */
/*   Updated: 2018/12/08 20:39:32 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "errno.h"
#include <sys/types.h>
#include <dirent.h>

char			*ft_add_pass_to_name(t_ls_dir *element, char *pass,
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

t_ls_dir		*ft_read_next_entry(char *pass, char *name)
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

int				calc_nbr_element_in_a_row(int colums, int definite_size)
{
	return (colums / (definite_size));
}
