/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_inchain_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:16:16 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/24 15:59:04 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "pwd.h"
#include "time.h"

int test_fn(t_ls_dir *a, t_ls_dir *b)
{
    int i;
    i = 0;
    if (a->level > b->level)
        return(1);
    if ((a->type < b->type))
        return (0);
    if (a->stats.st_mtimespec.tv_sec < b->stats.st_mtimespec.tv_sec)
        return (0);
    while (a->name[i] && b->name[i] && a->name[i] == b->name[i])
        i++;    
    return (a->name[i] - b->name[i]);
}

void    ft_insert_inchain_list(t_ls_dir **chain, t_ls_dir *element, int (*compare)(t_ls_dir*, t_ls_dir*))
{
    t_ls_dir *i;

    compare = test_fn;
    i = *chain;
    if (!*chain)
    {
        *chain = element;
        return;
    }
    else if (!(compare(*chain, element)))
    {
        element->next = *chain;
        *chain = element;
        return;    
    }
    while (i->next && compare(i->next, element))
        i = i->next;
    element->next = i->next;
    i->next = element;
}