/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 13:19:43 by jaylor            #+#    #+#             */
/*   Updated: 2017/02/06 09:00:36 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_first(char *s, char c)
{
	char	*ftmp;
	char	*ctmp;

	if (!(ctmp = ft_strchr(s, c)))
		return (0);
	if (!(ftmp = ft_strchrfull("123456789", s)))
		return (1);
	if (ftmp - s < ctmp - s)
		return (0);
	return (1);
}
