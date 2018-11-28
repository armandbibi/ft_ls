/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_inchain_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:16:16 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/28 20:50:02 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "pwd.h"
#include "time.h"

int		test_fn(t_ls *ls, t_ls_dir *a, t_ls_dir *b)
{
(void)ls;

	int i = 0;
	// if (a->arg != b->arg)
	// 	return (0);
	if (a->type > b->type)
		return(0);
	if (a->type < b->type)
		return(1);
	while (a->name[i] && b->name[i] && a->name[i] == b->name[i])
		i++;
	if (a->name[i] >= b->name[i])
		return (0);
	return (1);
}

void	ft_insert_inchain_list(t_ls *ls, t_ls_dir **chain, t_ls_dir *element,
		int (*compare)(t_ls*,t_ls_dir*, t_ls_dir*))
{
	t_ls_dir *i;

	element->next = NULL;
	compare = test_fn;
	i = *chain;

	ft_printf("\nm--------\n");
	while (i)
	{
		ft_printf(" %s(%d) ->", i->name, i->type);
		i = i->next;
	}
	ft_printf("\n--------\n");
	i = *chain;

	if (!chain || !i)
	{
		*chain = element;
		return ;
	}
	if (compare(ls, element, *chain))
	{
		element->next = *chain;
		*chain = element;
		return;
	}
	t_ls_dir *j = i->next;
	while ((j = i->next))
	{
		if (j && !compare(ls, j, element))
		{
			element->next = j;
			i->next = element;
			return;
		}
		i = i->next;
	}
	i->next = element;
}
