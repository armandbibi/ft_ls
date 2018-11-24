/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:15:42 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/24 18:26:41 by abiestro         ###   ########.fr       */
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
    if (!current || !pass || !*current || !*pass)
        return (NULL);
    if (!(new_pass = malloc(sizeof(char) * (ft_strlen(pass) + ft_strlen(current) + 2))))
        return (NULL);
    new_pass[0] = 0;
    if (pass)
        ft_strcpy(new_pass, pass);
    ft_strcat(new_pass, "/");
    if (current)
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
    char            *new_pass;

    new_pass = NULL;
    dir = opendir(current_dir->name);
    if (!dir)
        return;
    ft_printf("%s :\n", current_dir->name);
    while ((i = readdir(dir)))
    {
        if (*i->d_name == '.')
            continue;
        new_pass = ft_add_pass_to_name(NULL, current_dir->name, i->d_name);
        if (!new_pass)
            continue;
        returned = lstat(new_pass, &info);
        new = ft_new_ls_dir(new_pass, 0);
        ft_copy_stat_info_to_ls_dir(new, &info);
        ft_insert_inchain_list(&ls->elements, new, test_fn);
    }
    closedir(dir);
    while ((new = ls->elements) && ls->elements->level)
    {
          if (ls->option & OPTION_l)
            display_l(new);
        else if (new->name && *new->name)
           ft_printf("%s ", new->name);
        ls->elements = ls->elements->next;
        ft_del_ls_dir(&new);
    }
    ft_printf("\n");
}