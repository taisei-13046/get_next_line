#include "get_next_line.h"

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

char	*join_save_and_buf(char *save, char *buf,
	size_t save_len, size_t buf_len)
{
	size_t	i;
	size_t	m;
	char	*ans;

	i = 0;
	ans = malloc(sizeof(char) * (save_len + buf_len + 1));
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

char	*ft_strjoin(char *save, char *buf)
{
	size_t	save_len;
	size_t	buf_len;

	if (!save)
		return (ft_strdup(buf));
	else if (!buf)
		return (ft_strdup(save));
	save_len = ft_strlen(save);
	buf_len = ft_strlen(buf);
	return (join_save_and_buf(save, buf, save_len, buf_len));
}
