/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 13:28:45 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/30 10:21:47 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	const char	*a;
	const char	*b;
	int			i;

	a = s1;
	b = s2;
	while (*a == *b && *a != '\0')
	{
		a++;
		b++;
	}
	if (*b == '\0' && *a == '\0')
		return (0);
	i = (unsigned char)*a - (unsigned char)*b;
	return (i);
}
