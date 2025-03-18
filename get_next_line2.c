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
