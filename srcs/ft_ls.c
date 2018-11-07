/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:22:55 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/07 15:03:46 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_ls *ft_init_ls()
{
    return (malloc(sizeof(t_ls)));
}

int     ft_ls(int ac, char **arguments)
{
	t_ls *ls;

    ls = ft_init_ls();
    if (!ls)
        return (0);
    ls = ft_parse_ls(ac, arguments, ls);
    // if (verification)
    //     ft_execute_ls();
    // ft_delete_ls_struct();
     return (0);
}
