/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:30:50 by abiestro          #+#    #+#             */
/*   Updated: 2018/11/07 14:26:55 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_ls.h"
#include <dirent.h>

int     main(int ac, char **av)
{
	
    (void) ac;
    (void) av;
    ft_ls(ac, av);
    return (0);
}
