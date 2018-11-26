/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:14:25 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/26 15:16:41 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls_dir	*ft_handler(t_ls *ls, t_ls_dir *element)
{
	if (element->type == BAD_ELEMENT)
		ft_display_bad_arguments(ls, element);
	else if (element->type == LS_DIR)
			ft_display_dir(ls, element);
	else if (element->type == LS_FILE)
		ft_display_files(ls, element);
	ft_del_ls_dir(&element);
	return (element);
}
