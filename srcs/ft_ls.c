/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:22:55 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/20 13:40:27 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     ft_ls(int ac, char **arguments)
{
	t_ls *ls;

    ls = malloc_ls();
    if (!ls)
        return (0);
    ls = ft_parse_ls(ac, arguments, ls);
    if (!ls)
        return (0);
    ft_display_files(ls, ls->elements);
    return (0);
}
