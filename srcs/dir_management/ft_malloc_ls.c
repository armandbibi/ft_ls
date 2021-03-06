/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:14:36 by abiestro          #+#    #+#             */
/*   Updated: 2018/12/10 15:17:22 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*malloc_ls(void)
{
	t_ls *new_ls;

	new_ls = malloc(sizeof(t_ls));
	if (!new_ls)
		return (NULL);
	new_ls->elements = NULL;
	new_ls->option = 0;
	new_ls->level = 0;
	new_ls->arg_count = 0;
	return (new_ls);
}

void	ft_del_ls(t_ls *ls)
{
	if (ls->blank)
		free(ls->blank);
	free(ls);
}
