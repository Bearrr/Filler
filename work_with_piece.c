
#include "filler.h"

int          check_piece(int fd, char *line)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while(line[i] <= 47 || line[i] >= 58)
        i++;
    g_fill.piece_x = ft_atoi(&line[i]);
    while (line[i] != ' ')
        i++;
    i++;
    g_fill.piece_y = ft_atoi(&line[i]);
    g_fill.piece = (char**)malloc(sizeof(char*) * g_fill.piece_x + 1);
    while (g_fill.piece_x > 0) {
        if (get_next_line(fd, &line) > 0)
        {
            g_fill.piece[j] = (char*)malloc(sizeof(char) * (ft_strlen(line) + 1));
            ft_bzero(g_fill.piece[j], ft_strlen((line) + 1));
            while (line[k]) {
                g_fill.piece[j][k] = line[k];
                k++;
            }
        }
        j++;
        k = 0;
        g_fill.piece_x--;
    }
    printf("%s", g_fill.piece[0]);
    printf("%s", g_fill.piece[1]);
    printf("%s", g_fill.piece[2]);
    printf("%s", g_fill.piece[3]);
    return (0);
}
