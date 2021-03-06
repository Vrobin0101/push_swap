/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:28:35 by spuisais          #+#    #+#             */
/*   Updated: 2019/10/26 11:42:54 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>

typedef	struct		s_file
{
	int				fd;
	char			*reste;
	struct s_file	*next;
}					t_file;

typedef struct		s_tile
{
	int				connections;
	char			**tile;
	struct s_tile	*next;
}					t_tile;

int					check_next(char *str);
int					get_next_line(const int fd, char **line);

#endif
