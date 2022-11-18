/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:06:51 by gverdyan          #+#    #+#             */
/*   Updated: 2022/04/09 19:51:23 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*temp;

	if (!lst)
		return (0);
	len = 1;
	temp = lst;
	while (lst->next)
	{
		len++;
		lst = lst->next;
	}
	lst = temp;
	return (len);
}
