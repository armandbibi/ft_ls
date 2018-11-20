/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:14:36 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/20 13:51:58 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls    *malloc_ls(void)
{
    t_ls *new_ls;

    new_ls = malloc(sizeof(t_ls));
    if (!new_ls)
        return (NULL);
    new_ls->dir_lst = NULL;
    new_ls->files_lst = NULL;
    new_ls->bad_arguments = NULL;
    new_ls->elements = NULL;
    new_ls->option = 0;
    return (new_ls);
}