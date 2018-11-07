/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:22:08 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/07 16:20:17 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ft_ls.h"

t_ls  *ft_ls_parse_arguments(t_ls *ls, int ac, char **av)
{
    int i;
    DIR *dir;
//    t_ls_dir *args;

    i = 1;
    while (i < ac)
    {
        if (!(dir = opendir(av[i])))
            ft_ls_manage_not_dir(ls, av[i]);
        // else
        //     ft_ls_add_new_directory(ls, av[i]);
        i++;
    }
    return (ls);
}