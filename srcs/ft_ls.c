/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:22:55 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/09 19:51:58 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     ft_ls(int ac, char **arguments)
{
	t_ls *ls;

    ls = malloc_ls();
    if (!ls)
        return (0);
    ls->display_option[0] = NULL;
    ls = ft_parse_ls(ac, arguments, ls);
    ft_display_bad_arguments(ls, ls->bad_arguments);
    ft_display_files(ls, ls->files_lst);
    ft_display_dir(ls, ls->dir_lst);
    // if (verification)
    //     ft_execute_ls();
    // ft_delete_ls_struct();
     return (0);
}
