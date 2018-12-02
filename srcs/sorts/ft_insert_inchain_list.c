/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_inchain_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:16:16 by abiestro          #+#    #+#             */
/*   Updated: 2018/12/02 17:09:35 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "pwd.h"
#include "time.h"

int					test_fn(t_ls *ls, t_ls_dir *a, t_ls_dir *b)
{
	int i;

	(void)ls;
	i = 0;
	if (a->level < b->level)
		return (0);
	if (a->type > b->type)
		return (0);
	if (a->type < b->type)
		return (1);
	if (OPTION_t && (a->stats)
	while (a->name[i] && b->name[i] && a->name[i] == b->name[i])
		i++;
	if (a->name[i] >= b->name[i])
		return (0);
	return (1);
}

int					reverse_fn(t_ls *ls, t_ls_dir *a, t_ls_dir *b)
{
	return (!test_fn(ls, a, b));
}

static int			easy_insert(t_ls_dir **chain, t_ls_dir *element)
{
	element->next = *chain;
	*chain = element;
	return (1);
}

void				ft_insert_inchain_list(t_ls *ls, t_ls_dir **chain,
		t_ls_dir *element, int (*compare)(t_ls*, t_ls_dir*, t_ls_dir*))
{
	t_ls_dir *i;
	t_ls_dir *j;

	element->next = NULL;
	compare = (ls->option & OPTION_r) ? reverse_fn : test_fn;
	i = *chain;
	if (!chain || !i)
	{
		*chain = element;
		return ;
	}
	else if (compare(ls, element, *chain) && easy_insert(chain, element))
		return ;
	while ((j = i->next))
	{
		if (j && !compare(ls, j, element))
		{
			element->next = j;
			i->next = element;
			return ;
		}
		i = i->next;
	}
	i->next = element;
}
