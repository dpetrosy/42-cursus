/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:37:52 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/17 22:37:54 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

typedef struct s_descriptors
{
	int	file_in;
	int	file_out;
}	t_fd;

typedef struct s_main_args
{
	int		argc;
	char	**argv;
	char	**envp;
}	t_args;

void	args_valid(int argc, t_fd fds);
void	set_args(t_args *args, int argc, char **argv, char **envp);
void	garbage_collector(t_fd *fds, int **pipes, int len);
void	error_message(char const *sms, int mode);
void	free_exec(char *operand, char **paths);

size_t	ft_strlen(char const *str);
char	**ft_split(char const *str, char c);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strnstr(char const *haystack, char const *needle, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif /* UTILS_H */
