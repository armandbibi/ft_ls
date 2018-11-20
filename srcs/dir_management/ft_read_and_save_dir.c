/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_save_dir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:03:57 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/20 14:26:54 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#include <sys/types.h>


#include <dirent.h>

int     ft_read_and_save_dir(t_ls *ls, t_ls_dir *current_dir)
{
    DIR *dir;
    struct dirent *i;
    (void) ls;

    dir = opendir(current_dir->name);
    ft_printf("\n%s :\n", current_dir->name);
    while ((i = readdir(dir)))
    {
        ft_printf("%s ", i->d_name);
    }
    ft_printf("\n");
    return (1);
}