/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bad_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:02:29 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/07 17:38:45 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void        ft_display_bad_arguments(t_ls_dir *chain)
{
    while (chain)
    {
        ft_printf("ft_ls: %s : %s\n", chain->name, strerror(chain->type));
        chain = chain->next;
    }
}