/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:38:49 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/11/18 22:16:43 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "pipex.h"
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

int	main(int argc, char **argv, char **envp)
{
	t_fd	fds;
	int		**pipes;
	t_args	args;

	fds.file_in = open(argv[1], O_RDONLY);
	fds.file_out = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	args_valid(argc, fds);
	set_args(&args, argc, argv, envp);
	pipes = open_pipes(argc);
	dup2(fds.file_in, pipes[0][0]);
	dup2(fds.file_out, pipes[argc - 3][1]);
	pipex(pipes, args);
	close_pipes(pipes, args.argc - 4);
	while (wait(NULL) != -1 || errno != ECHILD)
		;
	garbage_collector(&fds, pipes, args.argc - 2);
	return (0);
}

void	set_args(t_args *args, int argc, char **argv, char **envp)
{
	args->argc = argc;
	args->argv = argv;
	args->envp = envp;
}

void	args_valid(int argc, t_fd fds)
{
	if (argc < 5)
		error_message("\n[Arguments ERROR]: Arguments minimum count: 5\n", 1);
	if (fds.file_in < 0)
		error_message("\n[Input File ERROR]", 0);
	if (fds.file_out < 0)
		error_message("\n[Output File ERROR]", 0);
}
