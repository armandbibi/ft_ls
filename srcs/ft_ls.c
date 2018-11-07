/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:22:55 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/07 19:21:20 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     ft_ls(int ac, char **arguments)
{
	t_ls *ls;

    ls = malloc_ls();
    if (!ls)
        return (0);
    ls = ft_parse_ls(ac, arguments, ls);
    ft_display_bad_arguments(ls->bad_arguments);
    ft_display_files(ls->files_lst);
    ft_display_dir(ls->dir_lst);
    // if (verification)
    //     ft_execute_ls();
    // ft_delete_ls_struct();
     return (0);
}
