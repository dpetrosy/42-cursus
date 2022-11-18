/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:38:57 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/17 22:38:58 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>

int	**open_pipes(int argc)
{
	int	**pipes;
	int	i;

	i = -1;
	pipes = (int **)malloc(sizeof(int *) * (argc - 2));
	while (++i < argc - 2)
		pipes[i] = (int *)malloc(sizeof(int) * 2);
	i = -1;
	while (++i < argc - 2)
		pipe(pipes[i]);
	return (pipes);
}

void	pipex(int **pipes, t_args args)
{
	pid_t	id;
	int		i;

	i = -1;
	while (++i < args.argc - 3)
	{
		id = fork();
		if (id == -1)
			error_message("\n[Fork ERROR]", 0);
		if (id == 0)
		{
			if (dup2(pipes[i][0], 0) == -1 ||
					dup2(pipes[i + 1][1], 1) == -1)
				error_message("\n[Dup ERROR]", 0);
			close_pipes(pipes, args.argc - 4);
			my_exec(ft_split(args.argv[i + 2], ' '), args.envp);
		}
	}
}

void	my_exec(char **cmd, char **envp)
{
	char	**paths;
	char	*binary;
	char	*operand;
	int		i;

	paths = envp_parsing(envp);
	i = -1;
	while (paths[++i])
	{
		if (access(cmd[0], X_OK) == -1)
		{
			binary = ft_strjoin(paths[i], "/");
			operand = ft_strjoin(binary, cmd[0]);
			free(binary);
			if (access(operand, X_OK) == -1)
				continue ;
			execve(operand, cmd, envp);
			error_message("[Execve ERROR]", 0);
		}
		execve(cmd[0], cmd, envp);
		error_message("[Execve ERROR]", 0);
	}
	free_exec(operand, paths);
	error_message("[Access ERROR]", 0);
}

char	**envp_parsing(char **envp)
{
	char	*envp_path;
	char	**paths;
	int		i;

	i = -1;
	while (envp[++i])
		if (ft_strnstr(envp[i], "PATH=", 5))
			break ;
	envp_path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	paths = ft_split(envp_path, ':');
	free(envp_path);
	return (paths);
}

void	close_pipes(int **pipes, int i)
{
	while (i >= 0)
	{
		if (close(pipes[i][0]) == -1 ||
				close(pipes[i][1]) == -1)
			error_message("\n[Pipe Close ERROR]", 0);
		i--;
	}
}
