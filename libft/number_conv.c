/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:18:34 by vrobin            #+#    #+#             */
/*   Updated: 2019/06/18 05:40:42 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	int_conv(va_list args, t_detail *detail, char *buff)
{
	long long int i;

	if ((DET)->ifshort == 2)
		i = (char)va_arg(args, int);
	else if ((DET)->ifshort == 1)
		i = (short)va_arg(args, int);
	else if ((DET)->iflong == 1)
		i = va_arg(args, long int);
	else if ((DET)->iflong == 2)
		i = va_arg(args, long long int);
	else
		i = va_arg(args, int);
	if (i > 0 && (DET)->precision == -1)
		(DET)->precision = 0;
	if (i < 0)
	{
		i *= -1;
		(DET)->plus = 0;
		if (i > LONG_MIN)
			(DET)->nega = 1;
	}
	i = aff_number(buff, ft_itoa(i), detail);
	return (i);
}

size_t	uint_conv(va_list args, t_detail *detail, char *buff)
{
	unsigned long long ll;

	if ((DET)->ifshort == 2)
		ll = (unsigned char)va_arg(args, unsigned int);
	else if ((DET)->ifshort == 1)
		ll = (unsigned short int)va_arg(args, unsigned int);
	else if ((DET)->iflong == 1)
		ll = va_arg(args, unsigned long int);
	else if ((DET)->iflong == 2)
		ll = va_arg(args, unsigned long long int);
	else
		ll = va_arg(args, unsigned int);
	(DET)->space = 0;
	(DET)->plus = 0;
	ll = aff_number(buff, ft_itoa(ll), detail);
	return (ll);
}

size_t	hexa_conv(va_list args, t_detail *detail, char *buff)
{
	unsigned long long		ll;
	char					*tmp;

	if ((DET)->ifshort == 2)
		ll = (unsigned char)va_arg(args, unsigned int);
	else if ((DET)->ifshort == 1)
		ll = (unsigned short int)va_arg(args, unsigned int);
	else if ((DET)->iflong == 1)
		ll = va_arg(args, unsigned long int);
	else if ((DET)->iflong == 2)
		ll = va_arg(args, unsigned long long int);
	else
		ll = va_arg(args, unsigned int);
	(DET)->space = 0;
	(DET)->hexa = 1;
	tmp = ft_itoa_base(ll, (DET)->hexachar);
	ll = aff_number(buff, tmp, detail);
	return (ll);
}

size_t	octal_conv(va_list args, t_detail *detail, char *buff)
{
	unsigned long long int ll;

	(DET)->oct = 1;
	if ((DET)->ifshort == 2)
		ll = (unsigned char)va_arg(args, unsigned int);
	else if ((DET)->ifshort == 1)
		ll = (unsigned short int)va_arg(args, unsigned int);
	else if ((DET)->iflong == 1)
		ll = va_arg(args, unsigned long int);
	else if ((DET)->iflong == 2)
		ll = va_arg(args, unsigned long long int);
	else
		ll = va_arg(args, unsigned int);
	(DET)->space = 0;
	(DET)->oct = 1;
	ll = aff_number(buff, ft_itoa(ft_itooct(ll)), detail);
	return (ll);
}

size_t	bin_conv(va_list args, t_detail *detail, char *buff)
{
	long long int i;

	if ((DET)->ifshort == 2)
		i = (char)va_arg(args, int);
	else if ((DET)->ifshort == 1)
		i = (short)va_arg(args, int);
	else if ((DET)->iflong == 1)
		i = va_arg(args, long int);
	else if ((DET)->iflong == 2)
		i = va_arg(args, long long int);
	else
		i = va_arg(args, int);
	if (i > 0 && (DET)->precision == -1)
		(DET)->precision = 0;
	if (i < 0)
	{
		i *= -1;
		(DET)->plus = 0;
		(DET)->nega = 1;
	}
	i = aff_number(buff, ft_itoa_base(i, "01"), detail);
	return (i);
}
