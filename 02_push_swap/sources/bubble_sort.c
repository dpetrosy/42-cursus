/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:36:21 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:36:24 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bubble_sort.h"
#include "utils.h"

int	*get_nums(int nums_count, char **argv)
{
	int		*nums;
	char	**temp;
	int		indx[3];

	indx[0] = 0;
	indx[2] = -1;
	nums = (int *)malloc(sizeof(int) * nums_count);
	if (!nums)
		error_message("[MALLOC ERROR]: Dynamic memory allocation fault!\n");
	while (argv[++indx[0]])
	{
		temp = ft_split(argv[indx[0]], ' ');
		if (!temp)
			error_message("[MALLOC ERROR]: Dynamic memory alloc fault!\n");
		else if (temp[0] == NULL)
			free_matrix(temp, 1);
		else
		{
			indx[1] = -1;
			while (temp[++indx[1]])
				nums[++indx[2]] = ft_atoi(temp[indx[1]]);
			free_matrix(temp, get_matrix_size(temp));
		}
	}
	return (nums);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
	}
}

void	print_array(int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		ft_printf("%d ", arr[i]);
	ft_printf("\n");
}

int	*copy_into_sorted(int *arr, int size)
{
	int	*sorted;
	int	i;

	i = -1;
	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(arr);
		error_message("[MALLOC ERROR]: Can't allocate memory!");
	}
	while (++i < size)
		sorted[i] = arr[i];
	bubble_sort(sorted, size);
	return (sorted);
}
