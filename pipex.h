/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:03:27 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/04/03 19:52:41 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

//structure
typedef struct s_info {
	int	infile;
	int	outfile;
}	t_info;

// fonction

// parsing
int		open_file(char *argv, int i);
char	**ft_get_envp(char **envp);
char	*ft_get_path(char **envp, char *cmd);
void	ft_get_cmd(char *argv, char **cmd, char **flag);
char	*ft_get_path(char **envp, char *cmd);
char	**ft_get_envp(char **envp);
void	execute(char *argv, char **envp);

// heredoc
int		gnl(char **line);
void	heredoc(int argc, char *stop);

// pipe
void	ft_fils(char *argv, char **envp);

// error
void	msg_error(char *err);

#endif