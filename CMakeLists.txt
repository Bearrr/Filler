cmake_minimum_required(VERSION 3.7)
project(Filler)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES  main.c filler.c filler.h ft_bzero.c ft_memset.c ./Get_Next_Line/. ./Libft/. get_next_line.c get_next_line.h ft_strchr.c ft_strncpy.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnew.c ft_strsub.c ft_strcpy.c ft_putendl.c ft_putchar.c test.txt ft_strcmp.c ft_atoi.c ft_strstr.c ft_strncmp.c  work_with_piece.c work_with_plateau.c work_with_ned.c my_trun.c ft_putnbr.c ft_putstr.c)
add_executable(Filler ${SOURCE_FILES})