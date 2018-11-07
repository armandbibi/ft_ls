/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_dir_to_chain.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:50:31 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/07 16:54:58 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     ft_add_dir_to_chain(t_ls *ls,t_ls_dir *chain, t_ls_dir *element)
{
    if (ls->bad_arguments == chain)
        ls->bad_arguments = element;
    else if (ls->dir_lst == chain)
        ls->dir_lst = element;
    else if (ls->files_lst == chain)
        ls->files_lst = chain;
    else
        return (0);
    return (1);
}