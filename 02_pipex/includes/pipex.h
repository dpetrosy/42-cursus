/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:37:39 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/17 22:37:42 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "utils.h"

int		**open_pipes(int argc);
void	pipex(int **pipes, t_args args);
void	my_exec(char **cmd, char **envp);
char	**envp_parsing(char **envp);
void	close_pipes(int **pipes, int i);

#endif	/* PIPEX_H */
