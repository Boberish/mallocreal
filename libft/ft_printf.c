/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:14:31 by jaylor            #+#    #+#             */
/*   Updated: 2017/03/24 15:51:49 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		strprint2(t_print *h)
{
	if (h->prec)
	{
		if ((int)ft_strlen(h->s) >= h->prec)
			h->s[h->prec] = '\0';
	}
	h->slen = ft_strlen(h->s);
	if (h->wid > (int)h->slen)
	{
		(h->just == 1) ? ft_putstr(h->s) :
			ft_putxchar(' ', h->wid - (int)h->slen, h->ret);
		(h->just == 1) ? ft_putxchar(' ', h->wid - (int)h->slen, h->ret)
			: ft_putstr(h->s);
	}
	else
		ft_putstr(h->s);
	*h->ret += (ft_strlen(h->s));
	return (0);
}

int		parse(t_print *h)
{
	h->just = ft_strchr(h->eval, '-') != NULL ? 1 : 0;
	if ((ft_strchr(h->eval, '.')))
		h->prec = (int)ft_atoi((ft_strchr(h->eval, '.') + 1));
	h->sign = ft_strchr(h->eval, ' ') != NULL ? ' ' : h->sign;
	if ((h->s = ft_strchrfull("123456789", h->eval)))
	{
		if (*(h->s - 1) != '.')
			h->wid = (int)ft_atoi(ft_strchrfull("123456789", h->eval));
	}
	h->sign = ft_strchr(h->eval, '+') != NULL ? '+' : h->sign;
	h->hash = ft_strchr(h->eval, '#') != NULL ? 1 : 0;
	h->pad = ft_first(h->eval, '0');
	if (ft_strchr(h->eval, 'h'))
	{
		if (*(ft_strchr(h->eval, 'h') + 1) == 'h')
			h->hh = 1;
		else
			h->lh = 1;
	}
	parse2(h);
	return (0);
}

int		parse2(t_print *h)
{
	if (ft_strchr(h->eval, 'l'))
	{
		if (*(ft_strchr(h->eval, 'l') + 1) == 'l')
			h->ll = 1;
		else
			h->l = 1;
	}
	h->z = ft_strchr(h->eval, 'z') != NULL ? 1 : 0;
	h->j = ft_strchr(h->eval, 'j') != NULL ? 1 : 0;
	return (0);
}

int		ft_printf(char *format, ...)
{
	t_print	*h;

	h = ft_memalloc(sizeof(t_print));
	va_start(h->ap, format);
	h->i = 0;
	h->ret = (int*)malloc(sizeof(int));
	*(h->ret) = 0;
	while (format[h->i] != '\0')
	{
		while (format[h->i] != '%' && format[h->i] != '\0')
			ft_pfpchar(format[h->i++], h->ret);
		if (format[h->i] == '\0')
			break ;
		h->eval = &format[h->i];
		while (!(ft_strchr("sSpdDioOuUxXcC%*", *(h->eval + 1))))
			h->eval++;
		h->spe = *(ft_strchr("sSpdDioOuUxXcC*%", *(h->eval + 1)));
		h->eval = ft_strsub(format, h->i, h->eval - &format[h->i - 1]);
		clearstr(h);
		parse(h);
		ft_sort(h);
	}
	return (*h->ret);
}
