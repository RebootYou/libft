/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegros <clegros@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:09:22 by clegros           #+#    #+#             */
/*   Updated: 2023/10/15 22:16:00 by clegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*mainh;
	t_list	*temp;
	t_list	*new;

	if (!lst)
		return (NULL);
	mainh = ft_lstnew((*f)(lst->content));
	if (!mainh)
		return (NULL);
	temp = lst->next;
	while (temp != NULL)
	{
		new = ft_lstnew((*f)(temp->content));
		if (!new)
		{
			ft_lstclear(&mainh, d);
			return (NULL);
		}
		ft_lstadd_back(&mainh, new);
		temp = temp->next;
	}
	return (mainh);
}
