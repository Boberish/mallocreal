/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-maul <pde-maul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:16:57 by jaylor            #+#    #+#             */
/*   Updated: 2018/10/19 13:04:52 by pde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*realloc(void *ptr, size_t size)
{
	void *ret;

	if (!g_holder_head)
		return (NULL);
	if (ptr == NULL)
		return (malloc(size));
	else if (size == 0)
		free(ptr);
	else
	{
		ret = find_page(ptr, g_holder_head->tiny, size);
		if (ret == NULL)
		{
			ret = find_page(ptr, g_holder_head->small, size);
			if (ret == NULL)
			{
				ret = find_large(ptr, size);
				return ((ret == NULL) ? NULL : ret);
			}
		}
		return (ret);
	}
	return (NULL);
}

void	*find_page(void *ptr, t_pages *head, size_t size)
{
	t_pages *curr_p;
	t_pages *prev_p;
	int		size_of_page;

	curr_p = head;
	prev_p = head;
	if (head == NULL)
		return (NULL);
	size_of_page = (curr_p == g_holder_head->tiny) ?
	get_optimal_size(TINY, 's') : get_optimal_size(SMALL, 's');
	while (curr_p)
	{
		if ((long)ptr >= (long)curr_p && (long)ptr
		< size_of_page + (long)curr_p)
			return (find_ptr(ptr, curr_p, size));
		prev_p = curr_p;
		curr_p = curr_p->next;
	}
	return (NULL);
}

void	*find_ptr(void *ptr, t_pages *curr_p, size_t size)
{
	t_base_node *curr_n;

	curr_n = curr_p->head;
	while (curr_n)
	{
		if ((void*)curr_n + sizeof(t_base_node) == ptr)
			return (if_conditions(size, curr_n, ptr, curr_p));
		curr_n = curr_n->next;
	}
	return (NULL);
}

void	*dumb_realloc(size_t size, void *ptr)
{
	void *retmalloc;

	retmalloc = malloc(size);
	ft_strcpy(retmalloc, ptr);
	free(ptr);
	return (retmalloc);
}

void	*if_conditions(size_t size, t_base_node *curr_n,
void *ptr, t_pages *curr_p)
{
	if (size <= curr_n->size)
		return (dumb_realloc(size, ptr));
	if (curr_n->next == NULL)
	{
		if (curr_p->aval_mem > size - curr_n->size)
		{
			curr_p->aval_mem -= size - curr_n->size;
			curr_n->size = size;
			return (ptr);
		}
		return (dumb_realloc(size, ptr));
	}
	if (curr_n->next->is_free == 1 && size <=
	curr_n->size + curr_n->next->size)
	{
		curr_n->size = size;
		curr_n->next = curr_n->next->next;
		return (ptr);
	}
	else
		return (dumb_realloc(size, ptr));
}
