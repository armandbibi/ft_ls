/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:22:08 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/14 19:52:52 by abiestro         ###   ########.fr       */
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
        if (returned)
        {
            element->valid = 0;
            element->type = BAD_ELEMENT;
            // ft_add_dir_to_chain(ls, ls->bad_arguments, element, BAD_ELEMENT);
            ft_insert_inchain_list(&ls->elements, element, test_fn);
        }
        else if (!(S_ISDIR(info.st_mode)))
        {
            element->type = LS_DIR;
            element->valid = 1;
            ft_copy_stat_info_to_ls_dir(element, &info);
            ft_insert_inchain_list(&ls->elements, element, test_fn);
            // ft_add_dir_to_chain(ls, ls->files_lst, element, LS_FILE);
        }
        else
        {
            element->type = LS_FILE;
            ft_copy_stat_info_to_ls_dir(element, &info);
            ft_insert_inchain_list(&ls->elements, element, test_fn);            
        }
        i++;
    }
    return (ls);
}