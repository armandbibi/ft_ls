/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:47:47 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/07 21:54:03 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     ft_add_option(t_ls *ls, char *str)
{
    int i;
    int booli;

            (void) ls;
    i = 0;
    str++;
    while (*str)
    {
        booli = 0;
        while (DISPLAY_OPTION[i])
        {
            if (*str == DISPLAY_OPTION[i])
            {
                ft_printf("display : %c\n", *str);
                booli = 1;
            }
                // ft_set_display_option(ls, *str);
            i++;
        }
        i = 0;
        while (SORTING_OPTION[i])
        {
            if(*str == SORTING_OPTION[i])
            {   ft_printf("sort : %c\n", *str);
                // ft_set_sorting_option(ls, *str);
                booli = 1;
            }
            i++;
        }
        if (!booli)
            ft_printf("invalide option");
        i = 0;
        str++;
    }
    return 21;
}