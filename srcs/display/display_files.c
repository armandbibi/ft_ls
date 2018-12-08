/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:12:27 by abiestro          #+#    #+#             */
/*   Updated: 2018/12/08 17:14:19 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void				ft_format_time2(struct timespec *time, char *buff, int t)
{
	if (t > 10)
		ft_itoa(t, &buff[12], 10);
	else
	{
		buff[12] = ' ';
		ft_itoa(t, &buff[13], 10);
	}
	buff[14] = ':';
	t = time->tv_sec % 3600 / 60;
	if (t > 9)
		ft_itoa(t, &buff[15], 10);
	else
	{
		buff[15] = '0';
		ft_itoa(t, &buff[16], 10);
	}
}

void				ft_format_time(struct timespec *time, char *buff)
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
	ft_format_time2(time, buff, t);
}

void				ft_add_color(t_ls_dir *element)
{
	if (element->stats.st_mode & S_IEXEC && S_ISREG(element->stats.st_mode))
		ft_printf("\x1B[31m");
	if (S_ISDIR(element->stats.st_mode))
		ft_printf("\e[1m");
	if (S_ISLNK(element->stats.st_mode))
		ft_printf("\x1b[35m");
}

void				ft_display_files(t_ls *ls, t_ls_dir *chain)
{
	(void)ls;
	if (ls->option & OPTION_L)
		display_l(chain);
	else
	{
		ft_add_color(chain);
		ft_printf("%s ", chain->d_name);
		ft_printf("\033[0m ");
	}
}
