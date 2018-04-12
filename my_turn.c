/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_trun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:09:24 by ireva             #+#    #+#             */
/*   Updated: 2017/10/02 14:39:31 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		calc_prior(int i, int j, int pr)
{
	if (g_fill.prior >= pr)
	{
		g_fill.prior = pr;
		g_fill.x = i;
		g_fill.y = j;
	}
}

int			still_check_my_turn_mofo(int i, int j)
{
	int		x;
	int		y;
	int		pr;

	x = 0;
	y = 0;
	pr = 0;
	while (g_fill.piece_x > x)
	{
		while (g_fill.piece_y > y)
		{
			if (g_fill.piece[x][y] == '*')
			{
				if (g_fill.plat[i + x][j + y] == g_fill.p2
					|| g_fill.plat[i + x][j + y] == g_fill.pp2)
					return (0);
				pr = pr + g_fill.ned[i + x][j + y];
			}
			y++;
		}
		y = 0;
		x++;
	}
	calc_prior(i, j, pr);
	return (0);
}

int			check_my_turn(int i, int j)
{
	int		y;
	int		x;
	int		f;

	y = 0;
	x = 0;
	f = 0;
	while (g_fill.piece_x > x)
	{
		if (i + g_fill.piece_x > g_fill.ned_x
			|| j + g_fill.piece_y > g_fill.ned_y)
			return (0);
		while (g_fill.piece_y > y)
		{
			if (g_fill.plat[i + x][j + y] == g_fill.p1
				|| g_fill.plat[i + x][j + y] == g_fill.pp1)
				if (g_fill.piece[x][y] == '*')
					f++;
			y++;
		}
		y = 0;
		x++;
	}
	(f == 1) ? still_check_my_turn_mofo(i, j) : 0;
	return (0);
}

void		my_turn(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	g_fill.x = 0;
	g_fill.y = 0;
	while (g_fill.ned_x > i)
	{
		while (g_fill.ned_y > j)
		{
			check_my_turn(i, j);
			j++;
		}
		j = 0;
		i++;
	}
	ft_putnbr(g_fill.x);
	write(1, " ", 1);
	ft_putnbr(g_fill.y);
	write(1, "\n", 1);
}
