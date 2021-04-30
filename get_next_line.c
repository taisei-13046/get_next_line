#include "get_next_line.h"
//#define BUFFER_SIZE 1
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *save)
{
	int	i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *str)
{
	char	*ans;
	int		i;

	i = 0;
	ans = (char *)malloc((sizeof(char) * ft_strlen(str) + 1));
	if (!ans)
		return (NULL);
	while (str[i])
	{
		ans[i] = str[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

char	*ft_strjoin(char *save, char *buf)
{
	char	*ans;
	size_t	save_len;
	size_t	buf_len;
	size_t	i;
	size_t	m;

	if (!save)
		return (ft_strdup(buf));
	else if (!buf)
		return (ft_strdup(save));
	save_len = ft_strlen(save);
	buf_len = ft_strlen(buf);
	ans = malloc(sizeof(char) * (save_len + buf_len + 1));
	i = 0;
	while (i < save_len)
	{
		ans[i] = save[i];
		i++;
	}
	free(save);
	m = 0;
	while (m < buf_len)
	{
		ans[i] = buf[m];
		i++;
		m++;
	}
	ans[i] = '\0';
	return (ans);
}

int	split_save(char **save, char **line)
{
	size_t	save_len;
	char	*tmp;

	save_len = ft_strchr(*save);
	(*save)[save_len] = '\0';
	*line = ft_strdup(*save);
	tmp = ft_strdup(*save + save_len + 1);
	free(*save);
	*save = tmp;
	return (1);
}

int	split_all(char **save, char **line)
{
	int		save_len;

	save_len = ft_strchr(*save);
	if (save_len >= 0)
	{
		return (split_save(save, line));
	}
	else if (*save)
	{
		free(*line);
		*line = *save;
		*save = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			flag;
	static char	*save[0];
	char		*buf;
	ssize_t		rd_cnt;

	if ((*save == NULL) || (*save = 0))
		rd_cnt = 1;
	if (fd < 0 || !(*line) || BUFFER_SIZE <= 0)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (rd_cnt > 0)
	{
		rd_cnt = read(fd, buf, BUFFER_SIZE);
		buf[rd_cnt] = '\0';
		save[fd] = ft_strjoin(save[fd], buf);
		if (ft_strchr(save[fd]) >= 0)
		{
			free(buf);
			flag = split_save(&save[fd], line);
			return (flag);
		}
	}
	if (rd_cnt < 0)
		return (-1);
	flag = split_all(&save[fd], line);
	return (flag);
}

//#include <sys/types.h>
//#include <stdio.h>
//int    main(void)
//{
//    int        d = 1;
//    char    *line;
//    int        fd;
//    int        i = 1;
//    fd = open("test.txt", O_RDONLY);
//    printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
//    while (d == 1)
//    {
//        printf("---%dline---\n", i);
//        d = get_next_line(fd, &line);
//        printf("%s\t", line);
//        free(line);
//        printf("d : %d\n", d);
//        i++;
//    }
//	//d = get_next_line(fd, &line);
//	//printf("%s\t", line);
//	//printf("d : %d\n", d);
//    close(fd);
//    system("leaks a.out");
//    return (0);
//}
