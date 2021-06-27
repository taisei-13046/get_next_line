#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *str);
int		ft_strchr(char *save);
char	*ft_strjoin(char *save, char *buf);

#endif
