/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:40:15 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/26 14:14:43 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LS_H
# define T_LS_H
# define BAD_ELEMENT       1
# define LS_FILE           2
# define LS_DIR            3

# define OPTION_l           0b00001
# define OPTION_R           0b00010
# define OPTION_a           0b00100
# define OPTION_r           0b01000
# define OPTION_t           0b10000
# define LOOOONG_SPACE      "                                                 "


#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


typedef struct  s_ls t_ls;
typedef struct  s_ls_dir t_ls_dir;
struct          s_ls_dir
{
    char        *name;
    char        *d_name;
    int         valid;
    char        type;
    t_ls_dir    *next;
    t_ls_dir    *kids_dir;
    int         level;
    struct stat stats;

};

struct             s_ls
{
    t_ls_dir        *elements;
    int             level;
    int             term_width;
    int             option;
};


int                 ft_read_and_save_dir(t_ls *ls, t_ls_dir *current_dir);
t_ls_dir            *ft_handler(t_ls *ls, t_ls_dir *element);

#endif