/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:56:21 by ireva             #+#    #+#             */
/*   Updated: 2017/10/09 14:54:25 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		check_player(char *line)
{
	if (ft_strstr(line, "p1"))
	{
		g_fill.p1 = 'O';
		g_fill.pp1 = 'o';
		g_fill.p2 = 'X';
		g_fill.pp2 = 'x';
	}
	if (ft_strstr(line, "p2"))
	{
		g_fill.p1 = 'X';
		g_fill.pp1 = 'x';
		g_fill.p2 = 'O';
		g_fill.pp2 = 'o';
	}
}

int			main(void)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '$')
			check_player(line);
		if (ft_strstr(line, "Plateau"))
			check_plateau(fd, line);
		if (ft_strstr(line, "Piece"))
			check_piece(fd, line);
	}
	return (1);
}
