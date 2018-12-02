/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:25:23 by abiestro          #+#    #+#             */
/*   Updated: 2018/12/02 16:44:16 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "grp.h"
#include "pwd.h"
#include "time.h"
#include <sys/stat.h>

void				ft_set_perms2(char *buff, mode_t permission)
{
	if ((permission & S_IXUSR) && (S_ISUID & permission))
		buff[3] = 's';
	if (permission & S_IRGRP)
		buff[4] = 'r';
	if (permission & S_IWGRP)
		buff[5] = 'w';
	if (permission & S_IXGRP && !(S_ISGID & permission))
		buff[6] = 'x';
	if (!(permission & S_IXUSR) && (S_ISGID & permission))
		buff[6] = 'S';
	if ((permission & S_IXUSR) && (S_ISGID & permission))
		buff[6] = 's';
	if (permission & S_IROTH)
		buff[7] = 'r';
	if (permission & S_IWOTH)
		buff[8] = 'w';
	if (permission & S_IXOTH && !(S_ISVTX & permission))
		buff[9] = 'x';
	if (!(permission & S_IXOTH) && (S_ISVTX & permission))
		buff[9] = 'T';
	if ((permission & S_IXOTH) && (S_ISVTX & permission))
		buff[9] = 't';
}

static char			*ft_set_perms(char *buff, mode_t permission)
{
	if (S_ISBLK(permission))
		buff[0] = 'b';
	else if (S_ISCHR(permission))
		buff[0] = 'c';
	else if (S_ISDIR(permission))
		buff[0] = 'd';
	else if (S_ISFIFO(permission))
		buff[0] = 'p';
	else if (S_ISREG(permission))
		buff[0] = '-';
	else if (S_ISLNK(permission))
		buff[0] = 'l';
	else
		buff[0] = 's';
	if (permission & S_IRUSR)
		buff[1] = 'r';
	if (permission & S_IWUSR)
		buff[2] = 'w';
	if (permission & S_IXUSR && !(S_ISUID & permission))
		buff[3] = 'x';
	if (!(permission & S_IXUSR) && (S_ISUID & permission))
		buff[3] = 'S';
	ft_set_perms2(buff, permission);
	return (buff);
}

static void			print_l(t_ls_dir *element, char *time, char *perms)
{
	ft_printf("%.10s %2d %s %12s %5u %s ",
			ft_set_perms(perms, element->stats.st_mode),
			(element->stats.st_nlink) ? element->stats.st_nlink : 0,
			(element->stats.st_uid) ?
			getpwuid(element->stats.st_uid)->pw_name : "root",
			(element->stats.st_gid) ?
			getgrgid(element->stats.st_gid)->gr_name : "wheel",
			element->stats.st_size,
			(*time) ? &time[5] : "");
}

void				display_l(t_ls_dir *element)
{
	char time[40];
	char perms[12];
	char dest[800];

	ft_memset(time, ' ', 39);
	ft_memset(perms, '-', sizeof(char) * 11);
	time[39] = 0;
	perms[11] = 0;
	if (!element)
		return ;
	ft_format_time(&element->stats.st_mtimespec, time);
	print_l(element, time, perms);
	ft_add_color(element);
	ft_printf("%s \033[0m ", element->d_name);
	if (S_ISLNK(element->stats.st_mode))
	{
		dest[readlink(element->name, dest, 800)] = 0;
		ft_printf("-> %s", dest);
	}
	ft_printf("\n");
}
