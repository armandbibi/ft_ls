/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:25:23 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/27 15:55:31 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "grp.h"
#include "pwd.h"
#include "time.h"
#include <sys/stat.h>

static void			ft_set_month(char *buff, int month)
{
	if (month == 1)
		ft_strcpy(buff, "Jan");
	else if (month == 2)
		ft_strcpy(buff, "Feb");
	else if (month == 3)
		ft_strcpy(buff, "Mar");
	else if (month == 4)
		ft_strcpy(buff, "Apr");
	else if (month == 5)
		ft_strcpy(buff, "May");
	else if (month == 6)
		ft_strcpy(buff, "Jun");
	else if (month == 7)
		ft_strcpy(buff, "Jul");
	else if (month == 8)
		ft_strcpy(buff, "Aug");
	else if (month == 9)
		ft_strcpy(buff, "Sep");
	else if (month == 10)
		ft_strcpy(buff, "Oct");
	else if (month == 11)
		ft_strcpy(buff, "Nov");
	else if (month == 12)
		ft_strcpy(buff, "Dec");
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
	return (buff);
}

static char			*ft_format_time(struct timespec *time, char *buff)
{
	int t;

	t = time->tv_sec / 31536000 + 1970;
	ft_itoa(t, buff, 10);
	buff[4] = ' ';
	t = time->tv_sec % 31536000 / 2629746;
	if (t > 9)
		ft_set_month(&buff[5], t);
	else
	{
		buff[5] = ' ';
		ft_set_month(&buff[6], t);
	}
	buff[8] = ' ';
	t = time->tv_sec % 2629746 / 86400 + 1;
	if (t > 9)
		ft_itoa(t, &buff[9], 10);
	else
	{
		buff[9] = ' ';
		ft_itoa(t, &buff[10], 10);

	}
	buff[11] = ' ';
	t = time->tv_sec % 86400 / 3600 + 1;
	if (t > 10)
		ft_itoa(t, &buff[12], 10);
	else
	{
		buff[12] = ' ';
		ft_itoa(t, &buff[13], 10);
	}
	buff[14] = ':';
	t = time->tv_sec % 3600 / 60 + 1;
	if (t > 9)
		ft_itoa(t, &buff[15], 10);
	else
	{
		buff[15] = '0';
		ft_itoa(t, &buff[16], 10);
	}
	return (buff);
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
	ft_printf("%.10s %2d %s %12s %5u %s ",
			ft_set_perms(perms, element->stats.st_mode) ,
			element->stats.st_nlink,
			getpwuid(element->stats.st_uid)->pw_name,
			getgrgid(element->stats.st_gid)->gr_name,
			element->stats.st_size,
			&time[5]);
	ft_add_color(element);
	ft_printf("%s \033[0m ", element->d_name);
	if (S_ISLNK(element->stats.st_mode))
	{
		dest[readlink(element->name, dest, 800)] = 0;
		ft_printf("-> %s", dest);
	}
	ft_printf("\n");
}
