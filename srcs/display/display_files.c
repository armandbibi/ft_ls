/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:12:27 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/26 16:30:40 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_add_color(t_ls_dir *element)
{
	if (element->stats.st_mode & S_IEXEC && S_ISREG(element->stats.st_mode))
		ft_printf("\x1B[31m");
	if (S_ISDIR(element->stats.st_mode))
		ft_printf("\e[1m");
}

void		ft_display_files(t_ls *ls, t_ls_dir *chain)
{
	(void)ls;
	if (*chain->d_name == '.')
		return ;
	ft_add_color(chain);
	if (ls->option & OPTION_l)
		display_l(chain);
	else
		ft_printf("%s", chain->d_name);
	ft_printf("\033[0m ");
}
