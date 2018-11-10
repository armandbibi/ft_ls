/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:47:47 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/10 18:15:07 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     option_is_valid(t_ls *ls, char option)
{
    if (option == 'R')
        ls->option &= OPTION_R;
    if (option == 'l')
        ls->option &= OPTION_l;
    else
        return (0);
    return (1);
}

int     ft_add_option(t_ls *ls, char *str)
{
    int i;

    i = 0;
    str++;
    while (*str)
    {
        if (!option_is_valid(ls, *str))
        {
            ft_printf("invalide option : '%c' in");
            return (0);
        }
        str++;
    }
    return (1);
}