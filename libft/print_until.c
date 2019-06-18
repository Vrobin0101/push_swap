/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_until.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 05:11:33 by vrobin            #+#    #+#             */
/*   Updated: 2019/06/18 05:41:06 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char			*print_until(char *format, int *len)
{
	int i;

	i = 0;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	if (i > 0)
		write(1, format, i);
	*len += i;
	return ((const char *)format + i);
}
