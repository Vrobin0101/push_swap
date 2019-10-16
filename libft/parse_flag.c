/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:24:57 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 18:00:46 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		parse_stuff(const char **format, va_list args, t_detail **detail,
		int *len)
{
	if (**format == ' ')
	{
		(*DET)->space = 1;
		++*format;
		parse_flag(format, args, detail, len);
	}
	if (**format == '#')
	{
		(*DET)->diese = 1;
		++*format;
		parse_flag(format, args, detail, len);
	}
	if (**format == '+')
	{
		(*DET)->plus = 1;
		++*format;
		parse_flag(format, args, detail, len);
	}
}

void		parse_zero(const char **format, va_list args, t_detail **detail,
		int *len)
{
	int i;

	i = 0;
	if (**format == '0' && (*DET)->minus == 0)
	{
		++*format;
		if (**format == '-')
			parse_flag(format, args, detail, len);
		if (**format == '+')
		{
			(*DET)->plus = 1;
			++*format;
		}
		while (**format >= '0' && **format <= '9')
		{
			i = i * 10;
			i = i + (**format) - 48;
			++*format;
		}
		(*DET)->zero = i;
	}
}

void		parse_conv(const char **format, t_detail **detail)
{
	if (**format == 'h')
	{
		++*format;
		(*DET)->ifshort += 1;
		if (**format && **format == 'h')
		{
			(*DET)->ifshort += 1;
			++*format;
		}
	}
	if (**format == 'L')
	{
		++*format;
		(*DET)->iflong = 2;
	}
	if (**format == 'l')
	{
		++*format;
		(*DET)->iflong += 1;
		if (**format && **format == 'l')
		{
			(*DET)->iflong += 1;
			++*format;
		}
	}
}

void		parse_field(const char **format, t_detail **detail)
{
	int i;

	i = 0;
	if (**format >= '0' && **format <= '9')
	{
		while (**format >= '0' && **format <= '9')
		{
			i = i * 10;
			i = i + (**format) - 48;
			++*format;
		}
		(*DET)->field = i;
	}
}

void		parse_flag(const char **format, va_list args, t_detail **detail,
		int *len)
{
	int i;

	parse_stuff(format, args, detail, len);
	if (**format == '-')
	{
		(*DET)->minus = 1;
		++*format;
		parse_flag(format, args, detail, len);
	}
	parse_zero(format, args, detail, len);
	parse_field(format, detail);
	i = 0;
	if (**format == '.')
	{
		++*format;
		while (**format >= '0' && **format <= '9')
		{
			i = i * 10;
			i = i + (**format) - 48;
			++*format;
		}
		(*DET)->precision = i;
		(*DET)->precision += (i == 0) ? -1 : 0;
	}
	parse_conv(format, detail);
}
