/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:15:42 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/07 20:22:08 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#include <sys/types.h>


#include <dirent.h>

static void ft_proto_iteration(t_ls_dir *element)
{
    DIR *dir;
    struct dirent *i;

    dir = opendir(element->name);
    while ((i = readdir(dir)))
    {
        ft_printf("%s ", i->d_name);
    }
}

void        ft_display_dir(t_ls_dir *chain)
{
    while (chain)
    {
        ft_printf("\n\n%s:\n", chain->name);
        ft_proto_iteration(chain);
        chain = chain->next;
    }
}