/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:14:31 by jaylor            #+#    #+#             */
/*   Updated: 2017/03/24 15:51:49 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		justintprint2(t_print *h)
{
	if (h->spe == 'o' || h->spe == 'O')
	{
		h->s = unitoaintmaxts(h->ifree, 8);
		h->ifree = ft_atoi(h->s);
	}
	if ((h->spe == 'o' || h->spe == 'O') && h->hash)
		h->wid -= 1;
	h->sign = (h->ifree < 0) ? '-' : h->sign;
	if (h->spe == 'o' || h->spe == 'O')
		h->ilen = (int)ft_strlen(h->s);
	else if (h->ifsign == 0)
		h->ilen = ft_intlen(h->ifree);
	else
		h->ilen = ft_intlen(h->inofree);
	h->ilen = (h->prec < 1 && (ft_strchr(h->eval, '.'))
			&& h->ifree == 0) ? 0 : h->ilen;
	justintprint3(h);
	return (0);
}

int		justintprint3(t_print *h)
{
	if (h->just)
	{
		if (h->sign && h->spe != 'o')
		{
			ft_pfpchar(h->sign, h->ret);
			h->sign = '\0';
			h->wid -= 1;
		}
		(h->prec < h->ilen) ? h->prec :
			ft_putxchar('0', h->prec - h->ilen, h->ret);
		if ((h->spe == 'o' || h->spe == 'O') && h->hash)
			ft_pfpchar('0', h->ret);
		pfilter(h);
		*h->ret += (h->ifsign == 0) ? ft_intlen(h->ifree) :
			ft_intlen(h->inofree);
		justwid(h);
	}
	else
		intprint(h);
	return (0);
}

int		charprint(t_print *h)
{
	h->ifree = va_arg(h->ap, int);
	if (h->just)
	{
		if (h->wid)
		{
			ft_pfpchar(h->ifree, h->ret);
			ft_putxchar(' ', h->wid - 1, h->ret);
		}
	}
	else
	{
		if (h->wid)
		{
			if (h->pad)
				ft_putxchar('0', h->wid - 1, h->ret);
			else
				ft_putxchar(' ', h->wid - 1, h->ret);
		}
		ft_pfpchar(h->ifree, h->ret);
	}
	return (0);
}

int		ft_sort(t_print *h)
{
	if (h->spe == 's' || h->spe == '%')
		strprint(h);
	if (h->spe == 'i' || h->spe == 'd' || h->spe == 'o' || h->spe == 'u' ||
			h->spe == 'U' || h->spe == 'D' || h->spe == 'O')
		justintprint(h);
	if (h->spe == 'x' || h->spe == 'X' || h->spe == 'p')
		hexprint(h);
	if (h->spe == 'c' || h->spe == 'C')
		charprint(h);
	h->i += (ft_strlen(h->eval) + 1);
	return (0);
}

int		strprint(t_print *h)
{
	if (h->spe != '%')
	{
		h->s = ft_strdup(va_arg(h->ap, char*));
		if (h->s == NULL)
		{
			ft_putstr("(null)");
			return (0);
		}
	}
	else
		h->s = "%";
	if (h->s == NULL)
	{
		ft_putstr("(null)");
		return (0);
	}
	strprint2(h);
	return (0);
}
