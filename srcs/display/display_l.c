/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:25:23 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/24 15:19:51 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "grp.h"
#include "pwd.h"
#include "time.h"

static void ft_set_month(char *buff, int month)
{
    month++; 
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

static char *ft_format_time(struct timespec *time, char *buff)
{
    int t;
    t = time->tv_sec / 31536000 + 1970;
    ft_itoa(t, buff, 10);
    buff[4] = ' ';
    t = time->tv_sec % 31536000 / 2629746;
    ft_set_month(&buff[5], t);
    buff[8] = ' ';
    t = time->tv_sec % 2629746 / 86400 + 1;
    ft_itoa(t, &buff[9], 10);
    buff[10] = ' ';
    t = time->tv_sec % 86400 / 3600 + 1;
    ft_itoa(t, &buff[11], 10);
    buff[13] = ':';
    t = time->tv_sec % 3600 / 60 + 1;
    ft_itoa(t, &buff[14], 10);
    return (buff);
}

void    display_l(t_ls_dir *element)
{
    char time[40];

    ft_memset(time, ' ', 39);
    time[39] = 0;
    if (!element)
    return;
    ft_format_time(&element->stats.st_mtimespec, time);
    ft_printf("%0.7d %3d %12s %12s %5u %s %s\n",
    element->stats.st_mode,
    element->stats.st_nlink,
    getpwuid(element->stats.st_uid)->pw_name,
    getgrgid(element->stats.st_gid)->gr_name,
    element->stats.st_size,
    time,
    element->name);
}