/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:05:10 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/12 09:56:30 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		sign;

	sign = n;
	len = ft_intlen(n);
	num = (char*)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	if (n == 0)
		*num++ = '0';
	while (n)
	{
		*num = ft_abs(n % 10) + 48;
		n /= 10;
		num++;
	}
	if (sign < 0)
		*num++ = '-';
	*num = '\0';
	num -= len;
	ft_strrev(num);
	return (num);
}
