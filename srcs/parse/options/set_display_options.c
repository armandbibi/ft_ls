/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_display_options.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:58:31 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/09 16:52:28 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_set_display_option(t_ls *ls, char option)
{
    int i;
    void        (*op)(t_ls_dir *);
    
    i = 0;
    if (option == 'l')
    {
        op = &display_l;
    }
    while (i < 4 && ls->display_option[i])
        i++;
    ls->display_option[0] = op;
}