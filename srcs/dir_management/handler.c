/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:14:25 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/24 20:33:34 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls_dir	*ft_handler(t_ls *ls, t_ls_dir *element)
{
	if (element->type == BAD_ELEMENT)
		ft_display_bad_arguments(ls, element);
	else if (element->type == LS_DIR)
	{
		if (ls->option & OPTION_R)
			ft_read_and_save_dir(ls, element);
		else
			ft_display_dir(ls, element);
	}
	else if (element->type == LS_FILE)
		ft_display_files(ls, element);
	ft_del_ls_dir(&element);
	return (element);
}
