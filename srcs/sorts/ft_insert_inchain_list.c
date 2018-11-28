/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_inchain_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:16:16 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/28 19:08:56 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "pwd.h"
#include "time.h"

int		test_fn(t_ls *ls, t_ls_dir *a, t_ls_dir *b)
{
(void)ls;

	if (a->type > b->type)
		return(0);
	if (ft_strcmp(a->name, b->name) > 0)
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




	if (!chain || !i)
	{
		*chain = element;
		return ;
	}
	if (compare(ls, *chain, element))
	{
		element->next = *chain;
		*chain = element;
		return;
	}
	t_ls_dir *j = i;
	while ((i))
	{
		j = i;
		i = i->next;
		if (i && compare(ls, i, element))
		{
			if (i->next)
			element->next = i;
			j->next = element;
			return;
		}
		if (!i)
		{
			j->next = element;
			return;
		}
	}
}
