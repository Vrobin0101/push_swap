/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:16:36 by vrobin            #+#    #+#             */
/*   Updated: 2019/06/18 05:40:34 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;

	len = 0;
	va_start(args, format);
	if (ft_strcmp(format, "%") == 0)
		return (0);
	while (*format && format)
	{
		if (*format != '%')
			format = print_until((char *)format, &len);
		if (!*format)
			break ;
		if (*format == '%')
			parse_format(&format, args, &len);
		format++;
	}
	va_end(args);
	return (len);
}

t_detail			*set_det(t_detail *detail)
{
	if (!(DET = malloc(sizeof(t_detail))))
		return (NULL);
	(DET)->strlen = 0;
	(DET)->number = 0;
	(DET)->field = 0;
	(DET)->precision = 0;
	(DET)->zero = 0;
	(DET)->hexa = 0;
	(DET)->hexachar = "0123456789abcdef";
	(DET)->maj = 0;
	(DET)->diese = 0;
	(DET)->sign = 0;
	(DET)->oct = 0;
	(DET)->iflong = 0;
	(DET)->ifshort = 0;
	(DET)->minus = 0;
	(DET)->plus = 0;
	(DET)->space = 0;
	(DET)->nega = 0;
	(DET)->len = 0;
	(DET)->iffloat = 0;
	(DET)->overbuff = 0;
	return (detail);
}

size_t				go_fct(const char *format, char *buff, va_list args,
		t_detail *detail)
{
	static size_t		(*ft[])(va_list args, t_detail *detail, char *buff) =
	{					aff_char, aff_string, aff_pointer, int_conv,
		int_conv, octal_conv, uint_conv, hexa_conv,
		hexa_conv, float_conv, bin_conv, percent_conv, tab_i};
	int					i;
	int					len;
	const char			*str;

	str = "cspdiouxXfb%t";
	i = 0;
	while (i < 13)
	{
		if (*format == str[i])
		{
			if (str[i] == 'X')
			{
				(DET)->maj = 1;
				(DET)->hexachar = "0123456789ABCDEF";
			}
			len = (*ft[i])(args, DET, buff);
			break ;
		}
		i++;
	}
	return (len);
}

size_t				get_fct(const char *format, va_list args, t_detail *detail)
{
	int				len;
	int				i;
	char			*buff;
	const char		*str;

	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (0);
	if (*format == '\0' || format == NULL)
		return (0);
	len = go_fct(format, buff, args, detail);
	if ((DET)->overbuff)
	{
		if ((DET)->minus)
			(DET)->len += len;
		return ((DET)->len);
	}
	return (len);
}
