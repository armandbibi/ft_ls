/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stat_to_ls_dir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:24:22 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/24 20:30:36 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ft_ls.h"

int	ft_copy_stat_info_to_ls_dir(t_ls_dir *element, struct stat *info)
{
	ft_memcpy(&element->stats, info, sizeof(struct stat));
	return (1);
}
