/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-maul <pde-maul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:57:50 by pde-maul          #+#    #+#             */
/*   Updated: 2018/10/19 13:36:10 by pde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

char	check_between_nodes(t_pages *curr_p, size_t size)
{
	t_base_node *node;

	node = curr_p->head;
	while (node)
	{
		if (node->is_free == 1 && size <= node->size)
			return (1);
		node = node->next;
	}
	return (0);
}

size_t	get_optimal_size(size_t chunk_size, char letter)
{
	size_t initial;
	size_t shit;

	if (letter == 's')
	{
		initial = chunk_size * MALLOC_PER_PAGE;
		initial += sizeof(t_base_node) * MALLOC_PER_PAGE + sizeof(t_pages);
		shit = ((size_t)(initial / getpagesize()) + 1) * getpagesize();
		return (shit);
	}
	else
		return ((size_t)((chunk_size + sizeof(t_pages)) /
		getpagesize()) + 1) * getpagesize();
}

void	*new_mmap(size_t size, char letter)
{
	void *mmap_hold;

	mmap_hold = mmap(NULL, get_optimal_size(size, letter),
	PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (mmap_hold == MAP_FAILED)
		return (NULL);
	return (mmap_hold);
}

void	*find_spot(t_pages *current_page, size_t size)
{
	t_base_node *malloc_node;

	malloc_node = current_page->head;
	while (malloc_node)
	{
		if (malloc_node->is_free == 1 && size <= malloc_node->size)
			return (do_malloc(current_page, malloc_node, size));
		malloc_node = malloc_node->next;
	}
	return (NULL);
}

void	ft_putstr(char const *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		i++;
	}
	write(1, s, i);
}
