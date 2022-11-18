/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:09:22 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/22 20:09:32 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFFER_SIZE 69

char	*get_next_line(int fd);
char	*file_read(int fd, char *str);
char	*ret_line(char *str);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*updated_str(char *str);
size_t	ft_gnl_strlen(const char *c);

#endif /* GNL_H */
