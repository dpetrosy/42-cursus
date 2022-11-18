/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:55:17 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/29 17:56:24 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_args.h"
#include "error_manager.h"

int	check_args(int argc, char **argv)
{
	int		nums_count;
	char	**temp;

	temp = NULL;
	nums_count = 0;
	if (argc < 5)
	{
		error_message("[ARGUMENT COUNT ERROR]\n");
		return (1);
	}
	nums_count = get_nums_count(argv, &temp);
	if (nums_count == -1)
		error_message("[MALLOC ERROR]: Dynamic memory alloc fault!\n");
	else if (nums_count == -2 || nums_count < 4 || nums_count > 5)
		free_and_exit(temp, get_matrix_size(temp), "[ARGUMENT ERROR]\n");
	if (nums_count == -1 || nums_count == -2
		|| nums_count < 4 || nums_count > 5)
		return (1);
	return (0);
}

int	get_nums_count(char **argv, char ***temp)
{
	int		i;
	int		j;
	int		nums_count;

	i = 0;
	nums_count = 0;
	while (argv[++i])
	{
		*temp = ft_split(argv[i], ' ');
		if (!(*temp))
			return (-1);
		else if (check_split_len(*temp))
			return (-2);
		else
		{
			j = -1;
			while ((*temp)[++j])
				if (check_num((*temp)[j], &nums_count) == 1)
					return (-2);
			free_matrix(*temp, get_matrix_size(*temp));
		}
	}
	return (nums_count);
}

int	check_num(char *num, int *nums_count)
{
	int	i;

	i = 0;
	*nums_count += 1;
	if (ft_isdigit(num[0]) != 1 && num[0] != '+')
		return (1);
	while (num[++i])
		if (ft_isdigit(num[i]) != 1)
			return (1);
	if (check_num1(num) == 1)
		return (1);
	return (0);
}

int	check_num1(char *num)
{	
	int	len;

	len = ft_strlen(num);
	if (num[0] == '+' && num[1] == '0')
		return (1);
	else if (num[0] == '0' && num[1] != '\0')
		return (1);
	else if (num[0] == '+' && num[1] == '\0')
		return (1);
	else if (len < 10)
		return (100);
	else if (((num[0] == '+') && len > 11)
		|| (ft_isdigit(num[0]) == 1 && len > 10))
		return (1);
	else if (num[0] == '+' && (ft_strncmp(num, "+2147483647", len) > 0))
		return (1);
	else if (ft_strncmp(num, "2147483647", len) > 0)
		return (1);
	return (0);
}

int	check_split_len(char **temp)
{
	int	len;

	if (temp[0] == NULL)
		return (1);
	len = -1;
	while (temp[++len])
		;
	if (len != 1)
		return (1);
	return (0);
}
