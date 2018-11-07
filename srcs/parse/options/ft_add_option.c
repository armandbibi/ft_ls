/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:47:47 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/07 20:55:40 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     ft_add_option(t_ls *ls, char *str)
{
    int i;

            (void) ls;
    i = 0;
    str++;
    while (str)
    {
        while (DISPLAY_OPTION[i])
        {
            i++;
            // if(*str == DISPLAY_OPTION[i])
                // ft_set_option(ls, *str);
        }
        str++;
    }
    return 21;
}