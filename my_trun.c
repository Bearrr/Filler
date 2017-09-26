#include "filler.h"
int     prior_calc(int i, int j)
{
    int x;
    int y;
    int pr;

    x = 0;
    y = 0;
    pr = 0;
 //   printf("Eto PX = %d, Eto PY = %d, Eto I = %d,Eto j = %d", g_fill.piece_x, g_fill.piece_y, i,j);
    while(g_fill.piece_x > x)
    {
        while(g_fill.piece_y > y)
        {
            if(g_fill.piece[x][y] == '*')
            {
               pr = pr + g_fill.ned[i + x][j + y];
                if (g_fill.prior > pr)
                {
                    g_fill.prior = pr;
                    g_fill.x = i + x;
                    g_fill.y = j + y;
                }
              //  printf("PRIORITY %d\n", g_fill.prior);
              //  printf("FINAL X = %d\n", g_fill.x);
              //  printf("FINAL Y = %d\n", g_fill.y);
            }
            y++;
        }
        y = 0;
        x++;
    }
    return (pr);

}

int    check_my_turn(int i, int j)
{
    int y;
    int x;
    int f;
    int pr;

    y = 0;
    x = 0;
    f = 0;
    pr = 0;
        while(g_fill.piece_x > x)
    {
        if (i + g_fill.piece_x > g_fill.ned_x) {
           // printf("ETO HYINYA\n");
            return (0);
        }
        while(g_fill.piece_y > y)
        {
            if (j + g_fill.piece_y > g_fill.ned_y) {
              //  printf("ETO HYINYA\n");
                return (0);
            }
            if (g_fill.plat[i + x][j + y] == g_fill.p1) {
                if (g_fill.piece[x][y] == '*')
                    f = f + 1;
            }
            y++;
        }
        y = 0;
        x++;
    }
    if (f == 1) {
        //printf("Vse KRYTTTTOOOOOOOO, x = %d y = %d\n", i, j);
         prior_calc(i, j);
      /*  if (g_fill.prior > pr)
        {
            g_fill.prior = pr;
            g_fill.x = i;
            g_fill.y = j;
            printf("X = %d, Y = %d", g_fill.x = )
        }*/
    }
    /*if (f > 1 || f == 0) {
        printf("Eto dich  x = %d y = %d %d \n", i, j, f);
    }*/
    return (0);

}
void    my_turn()
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(g_fill.plat[i])
    {
        while(g_fill.plat[i][j])
        {
            check_my_turn(i, j);
            j++;
        }
        j = 0;
        i++;
    }
    printf("%d %d\n", g_fill.x, g_fill.y);
}
