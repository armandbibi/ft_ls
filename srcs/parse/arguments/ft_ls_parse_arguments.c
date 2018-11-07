/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:22:08 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/07 20:42:23 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ft_ls.h"

t_ls  *ft_ls_parse_arguments(t_ls *ls, int ac, char **av)
{
    int i;
    int returned;
    t_ls_dir *element;
    struct stat info;
 
    i = 1;
    while (i < ac && *av[i] == '-')
        i++;
    while (i < ac)
    {
        returned = lstat(av[i], &info);
        element = ft_new_ls_dir(av[i], 0);
        if (returned == -1)
            ft_add_dir_to_chain(ls, ls->bad_arguments, element, BAD_ELEMENT);
        else if (!(S_ISDIR(info.st_mode)))
        {
            ft_copy_stat_info_to_ls_dir(element, &info);
            ft_add_dir_to_chain(ls, ls->files_lst, element, LS_FILE);
        }
        else
        {
            ft_copy_stat_info_to_ls_dir(element, &info);
            ft_add_dir_to_chain(ls, ls->dir_lst, element, LS_DIR);
        }
        i++;
    }
    return (ls);
}