#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char    *get_next_line(int fd);
void    loop(int fd, char *buffer, char *line, char *rest);
char    *extract_line(char *buffer, char *line, char *rest);
void    no_new_line(char *buffer, char *line, char *rest);
void    new_line(char *buffer, char *line, char *rest);

char    *ft_substr(char *s, size_t start, size_t len);
void    ft_strjoin(char *s1, char *s2);
char    *ft_strdup(char *s);
size_t  ft_strlen(char *s);
char    *ft_strchr(char *s, int c);

# endif
