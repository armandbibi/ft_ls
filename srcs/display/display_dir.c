/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:15:42 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/22 17:23:12 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "errno.h"
#include <sys/types.h>
#include <dirent.h>



static char     *ft_add_pass_to_name(t_ls_dir *element, char *pass, char *current)
{
    char *new_pass;

    new_pass = NULL;
    if (!(new_pass = malloc(sizeof(char) * (ft_strlen(pass) + ft_strlen(current) + 1))))
        return (NULL);
    if (!new_pass || !current)
        return(NULL);
    ft_strcpy(new_pass, pass);
    ft_strcat(new_pass, "/");
    ft_strcat(new_pass, current);
    if (element)
        element->name = new_pass;
    return (new_pass);
}

void        ft_display_dir(t_ls *ls, t_ls_dir *current_dir)
{
   DIR             *dir;
    struct dirent   *i;
    struct stat     info;
    int             returned;
    t_ls_dir        *new;

    (void)ls;
    dir = opendir(current_dir->name);
    if (!dir)
        return;
    ft_printf("\n%s :\n", current_dir->name);
    while ((i = readdir(dir)))
    {
        if (*i->d_name == '.')
            continue;
        returned = lstat(ft_add_pass_to_name(NULL, current_dir->name, i->d_name), &info);
        new = ft_new_ls_dir(ft_add_pass_to_name(NULL, current_dir->name, i->d_name), 0);
        ft_copy_stat_info_to_ls_dir(new, &info);
        if (ls->option & OPTION_l)
            display_l(new);
        else
           ft_printf("%s ", i->d_name);
    }
    ft_printf("\n");
}