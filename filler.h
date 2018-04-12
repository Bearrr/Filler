/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:00:46 by ireva             #+#    #+#             */
/*   Updated: 2017/10/05 16:05:17 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H
# include "./libft/libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef	struct			s_fil
{
	int					piece_x;
	int					piece_y;
	int					plat_x;
	int					plat_y;
	char				p1;
	char				p2;
	char				pp1;
	char				pp2;
	char				**piece;
	char				**plat;
	int					**ned;
	int					ned_x;
	int					ned_y;
	int					x;
	int					y;
	int					prior;
	int					cord_x;
	int					cord_y;
}						t_fil;

t_fil					g_fill;
int						filler(int a);
void					check_piece(int fd, char *line);
void					check_plateau(int fd, char *line);
void					work_with_ned(void);
void					my_turn(void);

#endif
