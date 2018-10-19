/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-maul <pde-maul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:16:57 by pde-maul          #+#    #+#             */
/*   Updated: 2018/10/19 15:03:33 by pde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	print_address_mem(void *mem1, void *mem2, size_t nb)
{
	ft_print_addr(mem1);
	ft_putstr(" - ");
	ft_print_addr(mem2);
	ft_putstr(" : ");
	ft_putnbr(nb);
	ft_putstr(" octets\n");
}

void	show_alloc_mem(void)
{
	int i;

	i = 0;
	if (!g_holder_head)
	{
		ft_putstr("Sorry, nothing to print ... \n");
		return ;
	}
	print_page(g_holder_head->tiny, &i);
	print_page(g_holder_head->small, &i);
	print_large(g_holder_head->large, &i);
	ft_putstr("Total : ");
	ft_putnbr(i);
	ft_putstr(" octets \n");
}

void	print_page(t_pages *head, int *i)
{
	t_pages		*current_page;
	t_base_node	*current_node;

	if (head)
	{
		current_page = head;
		current_node = head->head;
		ft_putstr(((head == g_holder_head->tiny) ? "TINY : " : "SMALL : "));
		ft_print_addr(head);
		ft_putstr("\n");
		while (current_page)
		{
			while (current_node)
			{
				print_mid(current_node, i);
			}
			current_page = current_page->next;
			if (current_page)
				current_node = current_page->head;
		}
	}
}

void	print_mid(t_base_node *current_node, int *i)
{
	if (current_node->is_free == 0)
	{
		print_address_mem((void *)current_node + sizeof(t_base_node),
		(void *)current_node + sizeof(t_base_node) + current_node->size,
		current_node->size);
		*i += current_node->size;
	}
	current_node = current_node->next;
}

void	print_large(t_pages *head, int *i)
{
	t_pages *curr_p;

	curr_p = head;
	if (head)
	{
		ft_putstr(("LARGE : "));
		ft_print_addr(head);
		ft_putstr("\n");
	}
	while (curr_p)
	{
		if (curr_p->head->is_free == 0)
		{
			print_address_mem(curr_p->head, (void*)curr_p->head +
			curr_p->head->size, curr_p->head->size);
			*i += curr_p->head->size;
		}
		curr_p = curr_p->next;
	}
}
