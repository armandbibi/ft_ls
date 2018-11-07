/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:40:15 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/07 16:57:44 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LS_H
# define T_LS_H

typedef struct  s_ls t_ls;
typedef struct  s_ls_dir t_ls_dir;

struct          s_ls_dir
{
    char        *name;
    char        type;
    t_ls_dir    *next;
    t_ls_dir    *kids_dir;
};

struct             s_ls
{
    t_ls_dir        *dir_lst;
    t_ls_dir        *files_lst;
    t_ls_dir        *bad_arguments;
};

#endif