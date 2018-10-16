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

int		hexprint(t_print *h)
{
	if (h->spe == 'p')
	{
		h->inofree = va_arg(h->ap, uintmax_t);
		if (h->inofree == 0 && h->prec < 1 && (ft_strchr(h->eval, '.')))
		{
			ft_pfpchar('0', h->ret);
			ft_pfpchar('x', h->ret);
			return (0);
		}
		h->s = unitoaintmaxts(h->inofree, 16);
		h->s = ft_strjoin("0x", h->s);
	}
	else if (ifmod(h) == 0)
		h->ifree = va_arg(h->ap, unsigned int);
	h->wid -= (h->hash) ? 2 : 0;
	if (h->ifree == 0 && h->inofree == 0 && h->spe != 'p')
	{
		intprint(h);
		return (0);
	}
	if (h->spe != 'p')
		h->s = unitoaintmaxts(h->ifree, 16);
	h->ilen = (int)ft_strlen(h->s);
	hexprint2(h);
	return (0);
}

int		hexprint2(t_print *h)
{
	if (h->wid > h->ilen && h->pad && !(h->just))
		h->s = crazy(h);
	h->ilen = (int)ft_strlen(h->s);
	if (h->just)
	{
		(h->prec < h->ilen) ? h->prec :
		ft_putxchar('0', h->prec - h->ilen, h->ret);
		ifhash(h);
		ft_putstr(h->s);
		if (h->wid > h->ilen)
			(h->prec < h->ilen) ? ft_putxchar(' ', h->wid - h->ilen, h->ret)
				: ft_putxchar(' ', h->wid - h->prec, h->ret);
	}
	else
		return (hexprint3(h));
	*h->ret += (h->hash) ? ft_strlen(h->s) + 2 : ft_strlen(h->s);
	return (0);
}

int		hexprint3(t_print *h)
{
	h->pad = (h->prec) ? 0 : h->pad;
	if (h->prec > h->ilen)
	{
		h->prec -= h->ilen;
		if (h->wid)
			h->wid -= h->prec;
	}
	else
		h->prec = -1;
	hexwid(h);
	(h->prec > 0) ? ft_putxchar('0', h->prec, h->ret) : h->prec;
	ifhash(h);
	ft_putstr((h->spe == 'X') ? ft_allup(h->s) : h->s);
	*h->ret += (h->hash) ? ft_strlen(h->s) + 2 : ft_strlen(h->s);
	return (0);
}

int		intprint(t_print *h)
{
	h->pad = (h->prec) ? 0 : h->pad;
	if (h->prec > h->ilen)
	{
		h->prec -= h->ilen;
		h->wid -= (h->wid) ? h->prec : 0;
	}
	else
		h->prec = -1;
	intprint2(h);
	return (0);
}

int		intprint2(t_print *h)
{
	if (h->pad)
	{
		if (h->sign && (h->spe != 'o' || h->spe != 'O'))
			(h->sign != '-' || h->pad) ? ft_pfpchar(h->sign, h->ret) : 0;
		wid(h);
	}
	else
	{
		wid(h);
		if (h->sign)
		{
			if (h->sign != '-' || h->pad || h->prec)
			{
				(h->spe != 'o' && h->spe != 'O') ?
					ft_pfpchar(h->sign, h->ret) : 0;
				h->sign = '\0';
			}
		}
	}
	return (intprint3(h));
}
