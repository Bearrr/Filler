#include <unistd.h>
#include <stdio.h>
#include "filler.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


void         check_player(char *line)
{
    if (ft_strstr(line, "p1")) {
       // printf("Ya player 1\n");
        g_fill.p1 = 'O';
        g_fill.p2 = 'X';
    }
    if (ft_strstr(line, "p2")) {
       // printf("Ya player 2\n");
        g_fill.p2 = 'X';
    }

}

int         filler(int a)
{
    char *line;

    int fd;
    line = NULL;
    int h;
    int i;
    g_fill.prior = 2147483647;

    if ((fd = open("test.txt", O_RDONLY))== -1)
    {
        ft_putendl("open failed on file file");
        return  (-1);
    }
    while (get_next_line(fd, &line) > 0)
    {
        if (line[0] == '$')
            check_player(line);
        if (ft_strstr(line, "Plateau"))
             check_plateau(fd, line);
        if (ft_strstr(line, "Piece"))
             check_piece(fd, line);
    }
   // printf("\n");
    work_with_ned();
    my_turn();

    return (1);
}

