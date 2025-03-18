char    *ft_strjoin(char *s1, char *s2)
{
        char    *str;
        size_t  i;
        size_t  j;

        if (!s2)
                return (NULL);
        str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
        if (!str)
                return (NULL);
        i = -1;
        if (s1)
        {
                while (s1[++i])
                        str[i] = s1[i];
        }
        else
                i++;
        j = -1;
        while (s2[++j])
                str[i + j] = s2[j];
        str[i + j] = '\0';
        if (s1)
                free(s1);
        return (str);
}
char    *ft_strdup(char *s)
{
        char    *str;
        size_t  i;

        if (!s)
                return (NULL);
        str = malloc(sizeof(char) * (ft_strlen(s) + 1));
        if (!str)
                return (NULL);
        i = -1;
        while (s[++i])
                str[i] = s[i];
        str[i] = '\0';
        return (str);
}
size_t  ft_strlen(char *s)
{
        size_t  i;

        if (!s)
                return (0);
        i = 0;
        while (s[i])
                i++;
        return (i);
}
char    *ft_strchr(char *s, int c)
{
        char    chr;
        size_t  i;

        chr = (char)c;
        i = 0;
        if (chr == '\0')
                return ((char *)s + ft_strlen(s));
        while (s[i])
        {
                if (s[i] == chr)
                        return (&s[i]);
                i++;
        }
        return (NULL);
}
