/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_plateau.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:29:28 by ireva             #+#    #+#             */
/*   Updated: 2017/10/02 14:48:02 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		check_plat_cord(int fd, char *line)
{
	int i;

	i = 0;
	while (line[i] <= 47 || line[i] >= 58)
		i++;
	g_fill.plat_x = ft_atoi(&line[i]);
	g_fill.ned_x = g_fill.plat_x;
	while (line[i] != ' ')
		i++;
	i++;
	g_fill.plat_y = ft_atoi(&line[i]);
	g_fill.ned_y = g_fill.plat_y;
	g_fill.plat = (char**)malloc(sizeof(char*) * g_fill.plat_x + 1);
	g_fill.plat[g_fill.plat_x + 1] = NULL;
	get_next_line(fd, &line);
}

void		check_plateau(int fd, char *line)
{
	int		j;
	int		k;
	int		x;

	j = 0;
	k = 0;
	x = 4;
	check_plat_cord(fd, line);
	while (g_fill.plat_x > 0)
	{
		if (get_next_line(fd, &line) > 0)
		{
			g_fill.plat[j] = ft_strnew(ft_strlen(line));
			while (line[x])
			{
				g_fill.plat[j][k] = line[x];
				k++;
				x++;
			}
		}
		j++;
		k = 0;
		x = 4;
		g_fill.plat_x--;
	}
}
