/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:55:20 by ireva             #+#    #+#             */
/*   Updated: 2017/10/02 16:03:33 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		check_p_cord(char *line)
{
	int i;

	i = 0;
	g_fill.prior = 2147483647;
	while (line[i] <= 47 || line[i] >= 58)
		i++;
	g_fill.piece_x = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	i++;
	g_fill.piece_y = ft_atoi(&line[i]);
	g_fill.piece = (char**)malloc(sizeof(char*) * g_fill.piece_x + 1);
}

void		check_piece(int fd, char *line)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	check_p_cord(line);
	while (g_fill.piece_x > i)
	{
		if (get_next_line(fd, &line) > 0)
		{
			g_fill.piece[j] = ft_strnew((ft_strlen(line) + 1));
			while (line[k])
			{
				g_fill.piece[j][k] = line[k];
				k++;
			}
		}
		j++;
		k = 0;
		i++;
	}
	work_with_ned();
	my_turn();
}
