/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bad_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:02:29 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/24 20:32:39 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_display_bad_arguments(t_ls *ls, t_ls_dir *chain)
{
	(void)ls;
	ft_printf("ft_ls: %s: No such file or directory\n", chain->name);
}
