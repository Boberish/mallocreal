/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:18:47 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/11 18:50:17 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*prev;
	t_list	*now;

	if (!lst)
		return (NULL);
	first = (t_list*)malloc(sizeof(*first));
	if (!first)
		return (NULL);
	first = f(lst);
	lst = lst->next;
	prev = first;
	while (lst)
	{
		now = (t_list*)malloc(sizeof(*now));
		if (!now)
			return (NULL);
		now = f(lst);
		prev->next = now;
		lst = lst->next;
		prev = prev->next;
	}
	return (first);
}
