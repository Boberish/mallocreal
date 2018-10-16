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

int	intprint3(t_print *h)
{
	(h->prec > 0) ? ft_putxchar('0', h->prec, h->ret) : h->prec;
	if ((h->spe == 'o' || h->spe == 'O') && h->hash
			&& (!(h->ifree == 0) || (ft_strchr(h->eval, '.'))))
		ft_pfpchar('0', h->ret);
	pfilter(h);
	if (h->spe == 'o' || h->spe == 'O')
	{
		*h->ret += ft_strlen(h->s);
		return (0);
	}
	if (h->ifsign == 0)
		*h->ret += ft_intlen(h->ifree);
	else
		*h->ret += ft_intlen(h->inofree);
	return (0);
}

int	justwid(t_print *h)
{
	if (h->wid > h->ilen)
	{
		if (h->prec < h->ilen)
			ft_putxchar(' ', h->wid - h->ilen, h->ret);
		else
			(h->sign) ? ft_putxchar(' ', h->wid - h->prec, h->ret)
				: ft_putxchar(' ', h->wid - h->prec, h->ret);
	}
	return (0);
}

int	ifmod2(t_print *h)
{
	if (h->hh || h->lh || h->l || h->ll || h->z || h->j)
	{
		if (h->hh == 1)
			h->inofree = (unsigned char)h->inofree;
		else if (h->lh == 1)
			h->inofree = (unsigned short)h->inofree;
		else if (h->l == 1)
			h->inofree = (unsigned long int)h->inofree;
		else if (h->ll == 1)
			h->inofree = (unsigned long long int)h->inofree;
		else if (h->z == 1)
			h->inofree = (size_t)h->inofree;
		else if (h->j == 1)
			h->inofree = (intmax_t)h->inofree;
		return (1);
	}
	else
		return (0);
}

int	justintprint(t_print *h)
{
	if (h->spe == 'u' || h->spe == 'U')
	{
		if (h->spe == 'U')
			h->ifree = (unsigned long)va_arg(h->ap, long);
		else
		{
			h->inofree = (!(h->hh) && !(h->h) && !(h->lh) && !(h->l) &&
			!(h->ll) && !(h->z) && !(h->j)) ? va_arg(h->ap, unsigned int)
				: va_arg(h->ap, unsigned long long int);
			ifmod2(h);
			h->ifsign = 1;
		}
		h->sign = '\0';
	}
	else if (ifmod(h) == 0)
		justintprint4(h);
	return (justintprint2(h));
}

int	justintprint4(t_print *h)
{
	if (h->spe == 'O')
		h->ifree = va_arg(h->ap, unsigned long int);
	else if (h->spe == 'o')
		h->ifree = va_arg(h->ap, unsigned int);
	else if (h->spe == 'D')
		h->ifree = va_arg(h->ap, long);
	else
		h->ifree = va_arg(h->ap, int);
	return (0);
}
