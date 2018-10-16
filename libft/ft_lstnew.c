/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 09:00:01 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/11 20:00:08 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list*)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
		node->next = NULL;
		return (node);
	}
	node->content_size = content_size;
	node->content = malloc(content_size);
	node->content = ft_memcpy(node->content, (void*)content, content_size);
	node->next = NULL;
	return (node);
}
