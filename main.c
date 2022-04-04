/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:06:01 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/04/04 16:59:08 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_cmd(char *argv, char **cmd, char **flag)
{
	unsigned int	i;
	char			*first;

	i = 0;
	while (argv[i] != ' ')
		i++;
	first = (void *)malloc(sizeof(*first) * (i + 1));
	if (ft_strchr(argv, ' ') != NULL)
		*flag = ft_strdup(&argv[i + 1]);
	else
		*flag = NULL;
	ft_strlcpy(first, argv, i + 1);
	cmd[0] = first;
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

void	heredoc(int argc, char *stop)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (argc < 6)
		ft_putstr_fd("Usage : ./pipex here_doc LIMITER cmd cmd1 file\n", 1);
	if (pipe(fd) == -1)
		msg_error("pipe error");
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (gnl(&line) != 0)
		{
			if (ft_strncmp(line, stop, ft_strlen(stop)) == 0)
				exit (1);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	ft_fils(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		msg_error("pipe error\n");
	pid = fork();
	if (pid == -1)
		msg_error("fork error\n");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	i;
	int		n;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			n = 3;
			i.outfile = open_file(argv[argc - 1], 0);
			heredoc(argc, argv[2]);
		}
		else
		{
			n = 2;
			i.infile = open_file(argv[1], 2);
			i.outfile = open_file(argv[argc - 1], 1);
			dup2(i.infile, STDIN_FILENO);
		}
		while (n < argc - 2)
			ft_fils(argv[n++], envp);
		dup2(i.outfile, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
	ft_putstr_fd("Usage : ./pipex file1 cmd1 cmd2 file2\n", 1);
	return (0);
}
