#include "get_next_line.h"

char    *get_next_line(int fd)
{
        static char     *stash;
        char    *hold;
        char    *line;

        if (fd < 0 || BUFFER_SIZE <= 0)
                return (NULL);
        hold = NULL;
        line = NULL;
        if (stash != NULL)
        {
                if (ft_strchr(stash, '\n'))
                {
                        line = extract_line(stash);
                        hold = stash_create(stash);
                        free(stash);
                        stash = hold;
                        free(hold);
                        return (line);
                }
                hold = ft_strjoin(line, stash);
        }
        line = get_the_line(fd);
        stash = stash_create(line);
        line = (extract_line(line));
        if (hold)
                line = ft_strjoin(hold, line);
        return (line);
}
char    *get_the_line(int fd)
{
        char    *buffer;
        char    *line;
        size_t  r_bytes;

        line = NULL;
        buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
        r_bytes = 1;
        while (r_bytes > 0)
        {
                r_bytes = read(fd, buffer, BUFFER_SIZE);
                buffer[r_bytes] = '\0';
                line = ft_strjoin(line, buffer);
                if (ft_strchr(line, '\n'))
                        break ;
        }
        free(buffer);
        return (line);
}
char    *extract_line(char *line)
{
        char    *str;
        char    *nl_add;
        size_t  i;

        nl_add = ft_strchr(line, '\n');
        str = (char *)malloc(sizeof(char) * (nl_add - line + 1));
        if (!str)
                return (NULL);
        i = -1;
        while (line[++i] != '\n')
                str[i] = line[i];
        str[i] = '\n';
        str[++i] = '\0';
        free(line);
        return (str);
}
char    *stash_create(char *line)
{
        char    *stash;
        size_t  i;
        size_t  j;

        i = 0;
        while (line[i] != '\n')
                i++;
        i++;
        j = 0;
        while (line[i + j])
                j++;
        stash = (char *)malloc(sizeof(char) * (j + 1));
        j = -1;
        while (line[i + ++j])
                stash[j] = line[i + j];
        stash[j] = '\0';
        return (stash);
}
