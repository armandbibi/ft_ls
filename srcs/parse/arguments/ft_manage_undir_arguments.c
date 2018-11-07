/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_undir_arguments.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:48:14 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/07 16:51:32 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

int ft_ls_manage_not_dir(t_ls *ls ,char *str)
{
    int error;
    t_ls_dir *element;

    error = errno;
    element = ft_new_ls_dir(str, 0);
        if (!element)
            return (0);
    if (error == ENOENT)
        ft_add_dir_to_chain(ls, ls->bad_arguments, element);
    return (1);
}