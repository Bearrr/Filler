//
// Created by Ivan Reva on 13.09.2017.
//


#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

#include "./Libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>


typedef  struct         s_fil
{
    int                 piece_x;
    int                 piece_y;
    int                 plat_x;
    int                 plat_y;
    char                p1;
    char                p2;
    struct s_fil     *next;
    char               **piece;
    char               **plat;
    int                 ned_x;
    int                 x;
    int                 y;


}                       t_fil;

t_fil                   g_fill;
int     filler(int a);
int     check_piece(int fd, char *line);
int     check_plateau(int fd, char *line);
void        work_with_ned();


#endif //FILLER_FILLER_H
