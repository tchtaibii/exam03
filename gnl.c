char    *ft_strdup(char *str)
{
    char *new;
    int i = 0;

    while (str[i])
        i++;
    new = malloc(i + 1);
    i = 0;
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char    *get_next_line(int fd)
{
    static char l[8000000] = {0};
    int ret = 1;
    int i = 0;
    char buf;
    while (ret = read(fd, &buf, 1) > 0)
    {
        l[i] = buf;
        i++;
        if (buf == '\n')
            break;
    }
    l[i] = '\0';
    if (l[0] == 0)
        return 0;
    return (ft_stdup(l));
}