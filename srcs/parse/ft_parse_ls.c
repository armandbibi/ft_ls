/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:39:15 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/24 20:40:14 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*ft_parse_ls(int ac, char **av, t_ls *ls)
{
	if (ft_parse_option(ls, ac, av))
		ft_ls_parse_arguments(ls, ac, av);
	else
		return (NULL);
	return (ls);
}
