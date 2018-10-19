/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_large.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-maul <pde-maul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:56:50 by pde-maul          #+#    #+#             */
/*   Updated: 2018/10/19 13:32:04 by pde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*init_large_page(size_t size, t_pages **head)
{
	t_pages *real;

	*head = new_mmap(size + sizeof(t_pages), 'l');
	if (*head == NULL)
		return (NULL);
	real = *head;
	real->head = (t_base_node *)((void *)real + sizeof(t_pages));
	real->head->is_free = 1;
	real->head->size = size;
	real->next = NULL;
	return ((void *)1);
}

void	*large_malloc(size_t size, t_pages *head)
{
	t_pages *curr_p;

	curr_p = head;
	while (curr_p)
	{
		if (curr_p->head->is_free == 1 && curr_p->head->size >= size)
		{
			curr_p->head->is_free = 0;
			return (curr_p->head);
		}
		if (curr_p->next == NULL)
			break ;
		curr_p = curr_p->next;
	}
	curr_p->next = new_mmap(size + sizeof(t_pages), 'l');
	if (curr_p->next == NULL)
		return (NULL);
	curr_p = curr_p->next;
	curr_p->head = (t_base_node *)((void *)curr_p + sizeof(t_pages));
	curr_p->head->is_free = 0;
	curr_p->head->size = size;
	curr_p->next = NULL;
	return (curr_p->head);
}

void	*find_large(void *ptr, size_t size)
{
	t_pages *curr;

	if (g_holder_head->large == NULL)
		return (NULL);
	curr = g_holder_head->large;
	while (curr)
	{
		if (ptr == curr->head)
			return (dumb_realloc(size, ptr));
		else
			curr = curr->next;
	}
	return (NULL);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int index;

	index = 0;
	while ((dest[index] = src[index]) != '\0')
	{
		index++;
	}
	return (dest);
}
