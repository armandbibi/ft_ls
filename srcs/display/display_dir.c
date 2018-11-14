/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:15:42 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/14 18:10:31 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "errno.h"
#include <sys/types.h>
#include <dirent.h>

void        ft_display_dir(t_ls *ls, t_ls_dir *chain)
{
    struct stat info;
    
    (void)ls;
    while (chain)
    {
        if (lstat(chain->name, &info) == -1)
            ft_printf("ft_ls : %s : %s\n", chain->name, strerror(errno));
        else
        {
            // if (ls->display_option[0])
                // ls->display_option[0](chain);
            // else
                ft_printf("\n\n%s:\n", chain->name);
            // ft_proto_iteration(ls, chain);
        }
        chain = chain->next;
    }
}