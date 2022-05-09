# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 19:56:07 by dpetrosy          #+#    #+#              #
#    Updated: 2022/05/09 20:03:45 by dpetrosy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus clean fclean re

name=libft.a
compiler=cc
flags=-Wall -Wextra -Werror
src=$(wildcard *.c)
bsrc=$(wildcard ft_lst*.c)
objects=$(src:.c=.o)
bobjects=$(bsrc:.c=.o)

all : $(name) $(bonus)

$(name) : $(objects)
	ar rcs $(name) $(objects)

%.o : %.c
	$(compiler) $(flags) -c $< -o $@

bonus :	$(bobjects)
	ar rcs $(name) $(bobjects)

clean :
	rm -f $(objects)
	rm -f $(bobjects)

fclean : clean
	rm -f $(name)

re : fclean all
