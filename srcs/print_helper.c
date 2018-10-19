/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-maul <pde-maul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:03:39 by pde-maul          #+#    #+#             */
/*   Updated: 2018/10/19 13:04:17 by pde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	print_hex(int value)
{
	char const *base = "0123456789abcdef";

	if (value / 16 > 1)
		print_hex(value / 16);
	write(1, base + value % 16, 1);
}

void	ft_print_addr(void *addr)
{
	if (addr)
	{
		ft_putstr("0x10");
		print_hex((int)addr);
	}
}
