/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:58:44 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/28 14:46:16 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 1000
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft.h"

int					get_next_line(const int fd, char **line);

typedef struct		s_stat
{
	size_t			rl;
	char			*rest;
	char			*tmp;
}					t_stat;
#endif
