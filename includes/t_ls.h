/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:40:15 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/10 18:11:15 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LS_H
# define T_LS_H
# define BAD_ELEMENT       1
# define LS_DIR            2
# define LS_FILE           3

# define DISPLAY_OPTION     "l1"
# define SORTING_OPTION     "uU"

# define OPTION_l           0b01
# define OPTION_R           0b10

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


typedef struct  s_ls t_ls;
typedef struct  s_ls_dir t_ls_dir;

struct          s_ls_dir
{
    char        *name;
    char        type;
    t_ls_dir    *next;
    t_ls_dir    *kids_dir;
    struct stat stats;

};

struct             s_ls
{
    t_ls_dir        *dir_lst;
    t_ls_dir        *files_lst;
    t_ls_dir        *bad_arguments;
    int             option;
};

#endif