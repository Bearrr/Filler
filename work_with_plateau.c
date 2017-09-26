#include "filler.h"

int          check_plateau(int fd, char *line)
{
    int i;
    int j;
    int k;
    int h;
    int x;

    j = 0;
    k = 0;
    i = 0;
    x = 4;
    while(line[i] <= 47 || line[i] >= 58)
        i++;
    g_fill.plat_x = ft_atoi(&line[i]);
    g_fill.ned_x = g_fill.plat_x;
    while (line[i] != ' ')
        i++;
    i++;
    g_fill.plat_y = ft_atoi(&line[i]);
    g_fill.ned_y = g_fill.plat_y;
    g_fill.plat = (char**)malloc(sizeof(char*) * g_fill.plat_x + 1);
    get_next_line(fd, &line);
    while (g_fill.plat_x > 0) {
        if (get_next_line(fd, &line) > 0)
        {
            g_fill.plat[j] = (char*)malloc(sizeof(char) * (ft_strlen(line)));
            ft_bzero(g_fill.plat[j], ft_strlen(line));
            while (line[x]) {
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
    h = 0;
    while(h < 14) {
      //  printf("%s\n", g_fill.plat[h]);
        h++;
    }
    return (0);

}
