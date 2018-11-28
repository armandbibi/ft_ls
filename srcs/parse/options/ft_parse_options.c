/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:29:44 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/28 19:30:57 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_parse_option(t_ls *ls, int ac, char **av)
{
	int i;

	(void)ls;
	i = 1;
	while (i < ac && *av[i] == '-')
	{
		if (!ft_add_option(ls, av[i]))
		{
			ft_printf(" \"%s\"\n", av[i]);
			return (0);
		}
		i++;
	}
	return (1);
}
