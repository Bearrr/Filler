#include <unistd.h>
#include <stdio.h>
#include "filler.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


void         check_player(char *line)
{
    if (ft_strstr(line, "p1")) {
        g_fill.p1 = 'O';
        g_fill.pp1 = 'o';
        g_fill.p2 = 'X';
        g_fill.pp2 = 'x';
    }
    if (ft_strstr(line, "p2")) {
        g_fill.p1 = 'X';
        g_fill.pp1 = 'x';
        g_fill.p2 = 'O';
        g_fill.pp2 = 'o';
    }

}

int         filler(int a)
{
    char *line;

    int fd;
    line = NULL;

   fd = 0;
//   if ((fd = open("test.txt", O_RDONLY))== -1)
//    {
//        ft_putendl("open failed on file file");
//        return  (-1);
//    }
    while (get_next_line(fd, &line) > 0)
    {
        if (line[0] == '$')
            check_player(line);
        if (ft_strstr(line, "Plateau"))
             check_plateau(fd, line);
        if (ft_strstr(line, "Piece"))
             check_piece(fd, line);
    }
    return (1);
}

