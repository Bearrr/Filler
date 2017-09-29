#include "filler.h"

int         only_positive(int buff)
{
    if (buff < 0)
        buff = buff * -1;
    return (buff);
}

void create_prior() {
    int buff;
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < g_fill.ned_x)
    {
        while(j < g_fill.ned_y) {
            if (g_fill.plat[i][j] == g_fill.p2 || g_fill.plat[i][j] == g_fill.pp2)
                buff = 2147483647;
            else
                buff = (only_positive(i - g_fill.x)) + (only_positive(j - g_fill.y));
            if (g_fill.ned[i][j] == 0 )
                g_fill.ned[i][j] = buff;
            if (g_fill.ned[i][j] != 0)
                if (g_fill.ned[i][j] > buff)
                    g_fill.ned[i][j] = buff;
            j++;
        }
        j = 0;
        i++;
    }
}

void create_ned() {
    int i;
    int j;

    i = 0;
    j = 0;
    while (g_fill.ned_x > i)
    {
        while(g_fill.ned_y > j)
        {
            if (g_fill.plat[i][j] == g_fill.p2 || g_fill.plat[i][j] == g_fill.pp2) {
                g_fill.ned[i][j] = 2147483647;
                g_fill.x = i;
                g_fill.y = j;
                create_prior();
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void        work_with_ned() {

    int i;
    int j;
    int k;
    int h;

    k = 0;
    i = 0;
    j = 0;
    h = 0;
    g_fill.ned = (int **) malloc(sizeof(int *) * g_fill.ned_x + 1);
    g_fill.ned[g_fill.ned_x + 1] = NULL;
    ft_bzero(g_fill.ned, (size_t) (g_fill.ned_x));
    while (g_fill.ned_x > k) {
        g_fill.ned[i] = (int *) malloc(sizeof(int) * g_fill.plat_y + 1);
        ft_bzero(g_fill.ned[i], (size_t) (g_fill.plat_y + 1));
        i++;
        j++;
        k++;
    }
    create_ned();
    create_prior();
//k = 0;
//    while(h < 100)
//    {
//        while(k < 99)
//        {
//            printf("%10d", g_fill.ned[h][k]);
//            k++;
//        }
//        printf("\n");
//        k = 0;
//        h++;
//    }

//    create_prior(ned);

}
