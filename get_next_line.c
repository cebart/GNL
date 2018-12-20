#include "get_next_line.h"

static char	    *ft_too_much_read(char *str)
{
	char	*leftover;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if ((str[i] && !str[i + 1]) || !str[i])
	{
		ft_strdel(&str);
		return (NULL);
	}
	leftover = ft_strdup(str + i + 1);
	ft_strdel(&str);
	return (leftover);
}

static char		*ft_put_line(char *str)
{
	int		i;
	char	*line;

    i = ft_strlen(str);
	if(!(line = malloc(sizeof(char) * i + 1)))
        return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	static t_file	files[100]; /* OPEN_MAX*/
	int				ret;
	char			*str;


	str = ft_strnew(BUFF_SIZE + 1);
	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	if (!files[fd].buf)
		files[fd].buf = ft_strnew(BUFF_SIZE + 1);
	while (!(ft_strchr(files[fd].buf, '\n')))
	{
		ret = read(fd, str, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		str[ret] = '\0';
		files[fd].buf = ft_strjoin(files[fd].buf, str);
		if (ret == 0 && files[fd].buf[0] == '\0')
			return (0);
		if (ret == 0)
			break ;
	}
	*line = ft_put_line(files[fd].buf);
	files[fd].buf = ft_too_much_read(files[fd].buf);
	return (1);
}
