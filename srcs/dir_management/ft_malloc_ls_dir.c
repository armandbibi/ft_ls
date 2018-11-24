/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_ls_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:38:09 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/24 16:04:17 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls_dir    *ft_new_ls_dir(char *name, char type)
{
    t_ls_dir *new;

    new = malloc(sizeof(t_ls_dir));
    if (!new)
        return(0);
    if (!name)
        return (0);
    new->name = name;
    new->type = type;
    new->kids_dir = NULL;
    new->next = NULL;
    new->level = 0; 
    return (new);
}

void       ft_del_ls_dir(t_ls_dir *del)
{
    free(del->name);
    free(del);
}