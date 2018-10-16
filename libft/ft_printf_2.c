/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:14:31 by jaylor            #+#    #+#             */
/*   Updated: 2017/03/24 15:51:49 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_unputnbr(uintmax_t n)
{
	uintmax_t	nb;

	nb = n;
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

int		pfilter(t_print *h)
{
	if (h->prec < 1 && (ft_strchr(h->eval, '.')) && h->ifree == 0)
	{
		*(h->ret) = *(h->ret) - 1;
		return (1);
	}
	if (h->ifree < 0)
		h->ifree *= -1;
	if (h->sign == '-' && !(h->pad))
		ft_pfpchar('-', h->ret);
	if (h->spe == 'o' || h->spe == 'O')
	{
		ft_putstr(h->s);
		return (0);
	}
	if (h->ifsign == 0)
		ft_unputnbr(h->ifree);
	else
		ft_unputnbr(h->inofree);
	return (0);
}

char	*checkhashpad(t_print *h)
{
	char	*new;
	int		i;

	new = (char*)malloc(sizeof(char) * (ft_strlen(h->s) + h->wid + 3));
	i = 0;
	h->wid -= h->ilen;
	new[i++] = '0';
	new[i++] = 'x';
	while ((h->wid)--)
	{
		new[i] = '0';
		i++;
	}
	ft_strcpy(&new[i], h->s);
	h->s = new;
	h->hash = 0;
	return (new);
}

char	*crazy(t_print *h)
{
	char	*new;
	int		i;

	new = (char*)malloc(sizeof(char) * (ft_strlen(h->s) + h->wid + 3));
	i = 0;
	if (h->pad && h->wid)
	{
		h->wid -= h->ilen;
	}
	if (h->hash)
	{
		new[i++] = '0';
		new[i++] = 'x';
	}
	while ((h->wid)--)
	{
		new[i] = '0';
		i++;
	}
	ft_strcpy(&new[i], h->s);
	h->s = new;
	h->hash = 0;
	return (new);
}

int		wid(t_print *h)
{
	if (h->wid > h->ilen)
	{
		if (h->pad)
		{
			if (h->sign)
				ft_putxchar('0', h->wid - h->ilen - 1, h->ret);
			else
				ft_putxchar('0', h->wid - h->ilen, h->ret);
		}
		else
		{
			if (h->sign)
				ft_putxchar(' ', h->wid - h->ilen - 1, h->ret);
			else
				ft_putxchar(' ', h->wid - h->ilen, h->ret);
		}
	}
	return (0);
}
