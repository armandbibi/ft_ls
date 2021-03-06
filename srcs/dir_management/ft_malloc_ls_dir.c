/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_ls_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:38:09 by abiestro          #+#    #+#             */
/*   Updated: 2018/12/08 17:38:47 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls_dir	*ft_new_ls_dir(char *name, char type)
{
	t_ls_dir *new;

	if (!name)
		return (0);
	new = malloc(sizeof(t_ls_dir));
	if (!new)
		return (0);
	new->name = name;
	new->type = type;
	new->d_name = name;
	new->valid = 0;
	new->arg = 0;
	new->next = NULL;
	ft_memset(&new->stats, 0, sizeof(struct stat));
	new->level = 0;
	return (new);
}

t_ls_dir	*more_info_ls_dir(t_ls_dir *new, int level, int type, int arg)
{
	new->level = level + 1;
	new->type = type;
	new->arg = arg + 1;
	return (new);
}

void		ft_del_ls_dir(t_ls_dir **b)
{
	t_ls_dir *a;

	a = *b;
	if (!a)
		return ;
	if (a->name)
		free(a->name);
	if (a->d_name && a->d_name != a->name)
		free(a->d_name);
	*b = NULL;
	free(a);
}
