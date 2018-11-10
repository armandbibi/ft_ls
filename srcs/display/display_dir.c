/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:15:42 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/10 18:03:23 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "errno.h"
#include <sys/types.h>
#include <dirent.h>
/*
static void ft_proto_iteration(t_ls *ls, t_ls_dir *element)
{
    DIR *dir;
    struct dirent *i;
    t_ls_dir *kid;
    struct stat info;
    char buff[200];

    kid = NULL;
    ft_strcpy(buff, element->name);
    dir = opendir(element->name);
    if (lstat(element->name, &info) == -1)
        ft_printf("ft_ls : %s : %s\n",element->name, strerror(errno));
    else while (dir && (i = readdir(dir)))
    {
        if (ls->display_option[0])
        {
            ft_strcpy(buff, element->name);
            ft_strcat(buff, "/");
            ft_strcat(buff,i->d_name);
            if(lstat(buff, &info)!= -1)
           {
                kid = ft_new_ls_dir(buff, 0);
                ft_copy_stat_info_to_ls_dir(kid, &info);
                ls->display_option[0](kid);
            }
            else
                ft_printf("\n%s\n", strerror(errno));
        }
        else
            ft_printf("%s ", i->d_name);
    }
}
*/
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