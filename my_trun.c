#include "filler.h"

int    still_check_my_turn_mofo(int i, int j)
{
    int x;
    int y;
    int pr;

    x = 0;
    y = 0;
    pr = 0;
    while(g_fill.piece_x > x) {
        while (g_fill.piece_y > y) {
            if (g_fill.piece[x][y] == '*') {
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
    if (g_fill.prior >= pr) {
        g_fill.prior = pr;
        g_fill.x = i;
        g_fill.y = j;
}
    return (0);
}

int    check_my_turn(int i, int j)
{
    int y;
    int x;
    int f;

    y = 0;
    x = 0;
    f = 0;
    while(g_fill.piece_x > x) {
            if (i + g_fill.piece_x > g_fill.ned_x)
                return (0);
            while (g_fill.piece_y > y) {
                if (j + g_fill.piece_y > g_fill.ned_y)
                    return (0);
                if (g_fill.plat[i + x][j + y] == g_fill.p1 || g_fill.plat[i + x][j + y] == g_fill.pp1) {
                    if (g_fill.piece[x][y] == '*')
                        f++;
                }
                y++;
            }
            y = 0;
            x++;
        }
    if (f == 1) {
        still_check_my_turn_mofo(i, j);
//        pr = pr + g_fill.ned[g_fill.cord_x + i][g_fill.cord_y + y];
//        if (g_fill.prior > pr) {
//            g_fill.prior = pr;
//            g_fill.x = i;
//            g_fill.y = j;
//        }
    }
    else
        return(0);
    return (0);

}

void    my_turn()
{
    int i;
    int j;

    i = 0;
    j = 0;
    g_fill.x = 0;
    g_fill.y = 0;
    while(g_fill.ned_x > i)
    {
        while(g_fill.ned_y > j)
        {
            check_my_turn(i, j);
            j++;
        }
        j = 0;
        i++;
    }
//    printf("YA TYT i = %d j = %d", i , j);
    ft_putnbr(g_fill.x);
    write(1," ", 1);
    ft_putnbr(g_fill.y);
    write(1, "\n", 1);
}
