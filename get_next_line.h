#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include "get_next_line.h"
# define BUFF_SIZE 16

typedef struct	s_file
{
	char	*buf;
}				t_file;
int	get_next_line(const int fd, char **line);

#endif
