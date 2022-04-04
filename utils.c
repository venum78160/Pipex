/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:44:40 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/04/04 16:59:01 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
	{
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	}
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		msg_error("ouverture file");
	return (file);
}

void	execute(char *argv, char **envp)
{
	char		*path;
	char		*cmd;
	char		*flag;
	char		*pute[3];

	ft_get_cmd(argv, &cmd, &flag);
	path = ft_get_path(envp, cmd);
	pute[0] = path;
	pute[1] = flag;
	pute[2] = NULL;
	execve(path, pute, envp);
}

int	gnl(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}

char	**ft_get_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
			break ;
		i++;
	}
	return (ft_split(&envp[i][5], ':'));
}

char	*ft_get_path(char **envp, char *cmd)
{
	char	**path;
	char	*ret;
	char	*ret_tmp;
	int		i;

	i = 0;
	path = ft_get_envp(envp);
	while (path[i])
	{
		ret_tmp = ft_strjoin(path[i], "/");
		ret = ft_strjoin(ret_tmp, cmd);
		free(ret_tmp);
		free(path[i]);
		if (access(ret, 0) == 0)
			break ;
		i++;
		free(ret);
	}
	free (path);
	return (ret);
}
