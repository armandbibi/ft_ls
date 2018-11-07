/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_dir_to_chain.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:50:31 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/07 17:24:48 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     ft_add_dir_to_chain(t_ls *ls,t_ls_dir *chain, t_ls_dir *element, int code)
{
    if (code == BAD_ELEMENT)
        ls->bad_arguments = element;
    else if (code == LS_DIR)
        ls->dir_lst = element;
    else if (code == LS_FILE)
        ls->files_lst = element;
    else
        return (0);
    element->next = chain;
    return (1);
}