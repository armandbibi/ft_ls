/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:22:55 by abiestro          #+#    #+#             */
/*   Updated: 2018/12/02 16:48:49 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>
#include <stdio.h>

int	ft_ls(int ac, char **arguments)
{
	t_ls			*ls;
	t_ls_dir		*element;
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	element = NULL;
	ls = malloc_ls();
	if (!ls)
		return (0);
	ls->term_width = w.ws_col;
	ls = ft_parse_ls(ac, arguments, ls);
	if (!ls)
		return (0);
	while ((element = ls->elements))
	{
		ls->elements = ls->elements->next;
		ft_handler(ls, element);
		if (ls->elements && S_ISDIR(ls->elements->stats.st_mode))
			ft_printf("\n");
	}
	ft_del_ls(ls);
	return (0);
}
