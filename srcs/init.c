/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-maul <pde-maul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:58:25 by pde-maul          #+#    #+#             */
/*   Updated: 2018/10/19 13:35:34 by pde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*init_holder(void)
{
	g_holder_head = new_mmap(sizeof(g_holder_head), 'l');
	if (g_holder_head == NULL)
		return (NULL);
	g_holder_head->tiny = NULL;
	g_holder_head->small = NULL;
	g_holder_head->large = NULL;
	return ((void *)1);
}

void	*init_pages(size_t size, t_pages **head)
{
	t_pages *real;

	*head = new_mmap(size, 's');
	if (*head == NULL)
		return (NULL);
	real = *head;
	real->head = (t_base_node *)((void *)real + sizeof(t_pages));
	real->head->next = NULL;
	real->head->is_free = 1;
	real->head->size = (size <= TINY) ? TINY : SMALL;
	real->aval_mem = get_optimal_size(size, 's') - sizeof(t_pages);
	real->free_count = 0;
	real->next = NULL;
	return ((void *)1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}
