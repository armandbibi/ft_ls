/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:25:23 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/09 16:54:49 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    display_l(t_ls_dir *element)
{
    if (!element)
    return;
        ft_printf("idxmod, number, usrer, stuff size date and name %s\n", element->name);
}