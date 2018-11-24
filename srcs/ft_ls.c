/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:22:55 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/24 20:36:32 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_ls(int ac, char **arguments)
{
	t_ls		*ls;
	t_ls_dir	*element;

	element = NULL;
	ls = malloc_ls();
	if (!ls)
		return (0);
	ls = ft_parse_ls(ac, arguments, ls);
	while ((element = ls->elements))
	{
		ls->elements = ls->elements->next;
		ft_handler(ls, element);
	}
	ft_del_ls(ls);
	return (0);
}
