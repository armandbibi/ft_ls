/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:40:15 by abiestro          #+#    #+#             */
/*   Updated: 2018/12/08 20:18:17 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LS_H
# define T_LS_H
# define BAD_ELEMENT       1
# define LS_FILE           2
# define LS_DIR            3
# define OPTION_L           0b00001
# define OPTION_RR          0b00010
# define OPTION_A           0b00100
# define OPTION_R			0b01000
# define OPTION_T           0b10000
# define LOOOONG_SPACE      "                                                 "
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_ls		t_ls;
typedef struct s_ls_dir	t_ls_dir;
struct					s_ls_dir
{
	char			*name;
	char			*d_name;
	int				valid;
	char			type;
	t_ls_dir		*next;
	int				level;
	int				arg;
	struct stat		stats;
};

struct					s_ls
{
	t_ls_dir		*elements;
	t_ls_dir		*end;
	int				level;
	int				term_width;
	int				option;
	int				arg_count;
	int				nb;
};
#endif
