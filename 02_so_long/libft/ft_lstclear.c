/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:27:43 by gverdyan          #+#    #+#             */
/*   Updated: 2022/03/24 21:04:13 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*temp;

	temp = *lst;
	if (!lst || !del)
		return ;
	while (temp)
	{
		node = temp;
		temp = temp->next;
		ft_lstdelone(node, del);
	}
	*lst = NULL;
}
