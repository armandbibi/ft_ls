/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bad_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:02:29 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/10 18:41:23 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void        ft_display_bad_arguments(t_ls *ls, t_ls_dir *chain)
{
    (void)ls;
    while (chain)
    {
        ft_printf("ft_ls: %s: No such file or directory\n", chain->name, strerror(chain->type));
        chain = chain->next;
    }
}