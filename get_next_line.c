#include "get_next_line.h"

static char *get_reserve(int fd, char *buffer, char *reserve)
{
    ssize_t readline;
    char *p;

    readline = 1;
    while (readline != 0)
    {
        readline = read(fd, buffer, BUFFER_SIZE);
        if (readline  == -1)
            return (NULL);
        else if ( readline == 0)
            break;
        if (!reserve)
            return(ft_strdup(""));
        p = reserve;
        reserve = ft_strjoin(p, buffer);
        free(p);
        p = NULL;
        if (ft_strchr(reserve, '\n'))
            break;
    }
    return (reserve);
}

static char *subresrve(char *get_line)
{
    size_t i;
    char *reserve;

    i = 0;
    while (get_line[i] != '\n' && get_line[i] != '\0')
        i++;
    if (get_line[i] == '\0' || get_line[1] == '\0')                                                                                                                  // ila wsal '\0' ya3ni mn wra '\n' lqa '\0' or ila kan fih '\n' ela lbadya omn wraha f index 1 kayn '\0' ya3ni '\n' kant f index 0.
        return (0);
    reserve = ft_substr(get_line, i + 1, ft_strlen(get_line) - i);
    if (*reserve == '\0')
    {
        free(reserve);
        reserve = NULL;
    }
    reserve[i + 1] = '\0';
    return (reserve);
}

char *get_next_line(int fd)
{
    static char *reserve;
    char *line;
    char *buffer;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    line = get_reserve(fd, buffer, reserve);
    free(buffer);
    buffer = NULL;
    if (!line)
        return (NULL);
    reserve = subresrve(line);
    return (NULL);
}
