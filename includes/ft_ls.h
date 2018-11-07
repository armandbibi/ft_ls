/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:24:06 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/07 16:58:47 by abiestro         ###   ########.fr       */
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

int         ft_ls(int ac, char **av);
t_ls        *malloc_ls(void);

/*
** mallocs
*/

t_ls_dir    *ft_new_ls_dir(char *name, char type);


/*
** parse
*/
t_ls        *ft_parse_ls(int ac, char **av, t_ls *ls);
t_ls        *ft_ls_parse_arguments(t_ls *ls, int ac, char **av);
int         ft_ls_manage_not_dir(t_ls *ls, char *str);


/*
** ls_dir structure utils
*/

int     ft_add_dir_to_chain(t_ls *ls,t_ls_dir *chain, t_ls_dir *element);


#endif