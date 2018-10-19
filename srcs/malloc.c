/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-maul <pde-maul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:16:57 by pde-maul          #+#    #+#             */
/*   Updated: 2018/10/19 15:32:21 by pde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_holder	*g_holder_head = NULL;

void	*malloc(size_t size)
{
	if (size <= 0 || size == __UINT64_MAX__)
		return (NULL);
	if (g_holder_head == NULL)
	{
		if (init_holder() == NULL)
			return (NULL);
	}
	return (check_size(size));
}

void	*check_size(size_t size)
{
	if (size <= TINY)
	{
		if (g_holder_head->tiny == NULL)
			init_pages(size, &(g_holder_head->tiny));
		return ((g_holder_head->tiny == NULL) ? NULL
		: check_space(size, g_holder_head->tiny));
	}
	else if (size <= SMALL)
	{
		if (g_holder_head->small == NULL)
			init_pages(size, &(g_holder_head->small));
		return ((g_holder_head->small == NULL) ? NULL
		: check_space(size, g_holder_head->small));
	}
	else
	{
		if (g_holder_head->large == NULL)
			init_large_page(size, &(g_holder_head->large));
		return ((g_holder_head->large == NULL) ? NULL
		: large_malloc(size, g_holder_head->large));
	}
	return (NULL);
}

void	*check_space(size_t size, t_pages *head)
{
	t_pages *current_page;

	current_page = head;
	while (current_page)
	{
		if (current_page->free_count > 0 &&
		check_between_nodes(current_page, size) == 1)
			return (find_spot(current_page, size));
		else if (current_page->aval_mem >= (size + sizeof(t_base_node)))
			return (find_spot(current_page, size));
		if (current_page->next == NULL)
			break ;
		current_page = current_page->next;
	}
	return (add_node_pages(current_page, size));
}

void	*add_node_pages(t_pages *current_page, size_t size)
{
	current_page->next = new_mmap(size, 's');
	if (current_page->next == NULL)
		return (NULL);
	current_page = current_page->next;
	current_page->aval_mem = get_optimal_size(size, 's') - sizeof(t_pages);
	current_page->head = (t_base_node *)((void *)current_page
	+ sizeof(t_pages));
	current_page->free_count = 0;
	current_page->head->is_free = 1;
	current_page->head->size = (size <= TINY) ? TINY : SMALL;
	current_page->head->next = NULL;
	current_page->next = NULL;
	return (find_spot(current_page, size));
}

void	*do_malloc(t_pages *curr_p, t_base_node *node, size_t size)
{
	void *final;

	node->is_free = 0;
	node->size = size;
	curr_p->aval_mem -= size + sizeof(t_base_node);
	final = (void *)node + sizeof(t_base_node);
	node->next = final + size;
	node = node->next;
	node->is_free = 1;
	node->size = (size <= TINY) ? TINY : SMALL;
	node->next = NULL;
	return (final);
}
