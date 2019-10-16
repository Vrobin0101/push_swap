/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:52:19 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 18:01:44 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		percent_conv(va_list args, t_detail *detail, char *buff)
{
	size_t		u;
	char		*string;

	string = "%";
	(void)(args);
	(DET)->space = 0;
	if ((DET)->precision == -1)
		(DET)->precision = 0;
	(DET)->strlen = ft_strlen(string);
	buff = edit_ret(buff, string, detail);
	u = ft_strlen(buff);
	free(buff);
	return (u);
}
