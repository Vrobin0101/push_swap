/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:19:27 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 18:01:21 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		parse_format(const char **format, va_list args, int *len)
{
	int				i;
	t_detail		*detail;

	i = 0;
	++*format;
	DET = NULL;
	DET = set_det(DET);
	if (**format)
	{
		parse_flag(format, args, &detail, len);
		if (**format == ' ')
		{
			(DET)->space = 1;
			++*format;
			parse_flag(format, args, &detail, len);
		}
		if (ft_strchr("cspdiouxXfb%t", **format) != NULL || **format == '%')
			*len = *len + get_fct(*format, args, DET);
		else
			free(DET);
	}
}
