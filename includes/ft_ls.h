/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:24:06 by abiestro          #+#    #+#             */
/*   Updated: 2018/12/02 17:39:15 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include "ft_printf.h"
# include "t_ls.h"

/*
** initialisation
*/

int						ft_ls(int ac, char **av);
/*
** mallocs
*/

t_ls_dir				*ft_new_ls_dir(char *name, char type);
t_ls					*malloc_ls(void);
/*
** parse
*/
t_ls					*ft_parse_ls(int ac, char **av, t_ls *ls);
t_ls					*ft_ls_parse_arguments(t_ls *ls, int ac, char **av);
int						ft_ls_manage_not_dir(t_ls *ls, char *str);
int						ft_parse_option(t_ls *ls, int ac, char **av);
int						ft_add_option(t_ls *ls, char *str);
void					ft_set_display_option(t_ls *ls, char option);
void					ft_insert_inchain_list(t_ls *ls, t_ls_dir **chain,
		t_ls_dir *element, int (*compare)(t_ls*, t_ls_dir*, t_ls_dir*));
/*
** ls_dir structure utils
*/

int						ft_add_dir_to_chain(t_ls *ls, t_ls_dir *chain, t_ls_dir
		*element, int code);
int						ft_copy_stat_info_to_ls_dir(t_ls_dir *element,
		struct stat *info);
char					*ft_add_pass_to_name(t_ls_dir *element,
		char *pass, char *current);
t_ls_dir				*ft_read_next_entry(char *pass, char *name);
int						calc_nbr_element_in_a_row(int colums,
		int definite_size);
t_ls_dir				*more_info_ls_dir(t_ls_dir *new,
		int level, int type, int arg);

int						ft_read_and_save_dir(t_ls *ls, t_ls_dir *current_dir);
t_ls_dir				*ft_handler(t_ls *ls, t_ls_dir *element);
/*
** display
*/

void					ft_display_bad_arguments(t_ls *ls, t_ls_dir *chain);
void					ft_display_files(t_ls *ls, t_ls_dir *chain);
void					ft_display_dir(t_ls *ls, t_ls_dir *chain);
void					ft_add_color(t_ls_dir *element);
void					ft_format_time(struct timespec *time, char *buff);
void					display_l(t_ls_dir *element);
/*
** sorting
*/

int						test_fn(t_ls *ls, t_ls_dir *a, t_ls_dir *b);
/*
** free
*/

void					ft_del_ls_dir(t_ls_dir **del);
void					ft_del_ls(t_ls *ls);
#endif
