/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:26:25 by jaylor            #+#    #+#             */
/*   Updated: 2017/03/08 14:38:38 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		hexwid(t_print *h)
{
	if (h->wid > h->ilen)
		ft_putxchar(' ', h->wid - h->ilen, h->ret);
	return (0);
}

void	clearstr(t_print *h)
{
	h->just = 0;
	h->sign = '\0';
	h->s = NULL;
	h->spa = 0;
	h->pad = 0;
	h->hash = 0;
	h->wid = 0;
	h->prec = 0;
	h->len = 0;
	h->hh = 0;
	h->lh = 0;
	h->l = 0;
	h->ll = 0;
	h->z = 0;
	h->j = 0;
	h->slen = 0;
	h->ifree = 0;
	h->ilen = 0;
	h->ifsign = 0;
}

int		ifmod(t_print *h)
{
	if (h->hh || h->lh || h->l || h->ll || h->z || h->j)
	{
		if (h->hh == 1)
		{
			h->ifree = va_arg(h->ap, int);
			h->ifree = (char)h->ifree;
		}
		else if (h->lh == 1)
		{
			h->ifree = va_arg(h->ap, int);
			h->ifree = (short)h->ifree;
		}
		else if (h->l == 1)
			h->ifree = (h->spe == 'u') ? va_arg(h->ap, unsigned long int)
				: va_arg(h->ap, long);
		else if (h->ll == 1)
			h->ifree = va_arg(h->ap, long long);
		else if (h->z == 1)
			h->ifree = va_arg(h->ap, size_t);
		else if (h->j == 1)
			h->ifree = va_arg(h->ap, intmax_t);
		return (1);
	}
	else
		return (0);
}

int		ifhash(t_print *h)
{
	if (h->hash)
	{
		if (h->spe == 'X')
			ft_putstr("0X");
		else
			ft_putstr("0x");
	}
	return (0);
}

char	*unitoaintmaxts(uintmax_t value, unsigned short base)
{
	char	*ret;
	char	*dig;
	int		i;

	dig = "0123456789abcdef";
	if ((ret = malloc(sizeof(*ret) * (1000))))
	{
		i = 0;
		while (value != 0 || (i == 0))
		{
			ret[i++] = dig[value % base];
			value /= base;
		}
		ret[i] = 0;
		ft_strrev(ret);
	}
	return (ret);
}
