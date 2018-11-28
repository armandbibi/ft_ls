/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:22:08 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/28 15:03:11 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ft_ls.h"

t_ls	*ft_ls_parse_arguments(t_ls *ls, int ac, char **av)
{
	int			i;
	int			returned;
	t_ls_dir	*element;
	struct stat	info;

	i = 1;
	while (i < ac && *av[i] == '-')
		i++;
	while (i < ac)
	{
		returned = lstat(av[i], &info);
		element = ft_new_ls_dir(ft_strdup(av[i]), 0);
		if (returned)
			element->type = BAD_ELEMENT;
		else
			ft_copy_stat_info_to_ls_dir(element, &info);
		if (!returned && !(S_ISDIR(info.st_mode)))
			element->type = LS_FILE;
		else if (!returned && (S_ISDIR(info.st_mode)))
			element->type = LS_DIR;
		ft_insert_inchain_list(ls, &ls->elements, element, test_fn);
		i++;
	}
	element = ls->elements;
	element->arg = ls->nb++;
	while((element = element->next))
		element->arg = ls->nb++;
	return (ls);
}
