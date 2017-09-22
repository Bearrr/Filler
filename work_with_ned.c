#include "filler.h"

/*void create_prior(int **ned)
{
    int buff;
    int i;
    int j;

    i = 0;
    j = 0;
    while()
}
*/
void create_ned(int **ned) {
    int i;
    int j;
    int k;
    int h;

    i = 0;
    j = 0;
    k = 30;
    h = 0;
    while (g_fill.plat[i])
    {
        while(g_fill.plat[i][j])
        {
            if (g_fill.plat[i][j] == g_fill.p1) {
                printf("YA NASHEL\n");
                ned[i][j] = 7;
                g_fill.x = i;
                g_fill.y = j;
                break;
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void        work_with_ned() {
    int **ned;

    int i;
    int j;
    int h;
    int k;

    k = 0;
    i = 0;
    h = 0;
    j = 0;
    ned = (int **) malloc(sizeof(int *) * g_fill.ned_x + 1);
    ft_bzero(ned, (size_t) (g_fill.ned_x + 1));
    while (g_fill.ned_x > k) {
        ned[i] = (int *) malloc(sizeof(int) * g_fill.plat_y + 1);
        ft_bzero(ned[i], (size_t) (g_fill.plat_y + 1));
        i++;
        j++;
        k++;
    }
    create_ned(ned);

/*    while(h < 13)
    {
        while(k < 30)
        {
            printf("%d", ned[h][k]);
            k++;
        }
        printf("\n");
        k = 0;
        h++;
    }*/
//    create_prior(ned);

//    create_prior(ned);
}