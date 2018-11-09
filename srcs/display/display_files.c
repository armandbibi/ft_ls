/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:12:27 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/09 16:49:16 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void        ft_display_files(t_ls *ls, t_ls_dir *chain)
{
    if (ls->display_option[0])
        ls->display_option[0](chain);
    else while (chain)
    {
         if(chain->stats.st_mode & S_IXUSR)
            ft_printf("\033[0;31m ");
        ft_printf("%s", chain->name);
        ft_printf("\033[0m ");
        chain = chain->next;
    }
    ft_printf("\n");
}