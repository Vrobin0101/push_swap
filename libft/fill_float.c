/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 21:27:16 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 18:00:37 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	fill_rest(long long int a, long long int u, char **str)
{
	char	*tmp;

	tmp = ft_itoa(a);
	if (bol_nine(tmp) == 1)
		return (-1);
	if (tmp[ft_strlen(tmp) - 1] >= '5' && tmp[ft_strlen(tmp - 1)] <= '9')
	{
		a += 5;
		free(tmp);
		tmp = ft_itoa(a);
	}
	if (u > 0)
		*str = ft_strncat(*str, tmp, ft_strlen(tmp) - 1);
	free(tmp);
	return (a);
}

char			*fill_zero(char *str, long long int a, long long int u)
{
	char *tmp;

	if (!(tmp = ft_strnew(BUFF_SIZE)))
		return (NULL);
	if (a == 0)
	{
		while (a < u)
		{
			tmp[a] = '0';
			a++;
		}
		tmp[a + 1] = '\0';
	}
	str = ft_strcat(str, tmp);
	free(tmp);
	return (str);
}

size_t			ftoa(long double f, char *buff, t_detail *detail)
{
	long long int					u;
	long long int					i;
	long long int					a;
	char							*str;
	long double						rest;

	str = nega(&f, &rest, &a, detail);
	(DET)->hexachar = str;
	i = ft_strlen(str);
	u = (DET)->precision;
	while ((DET)->precision + 1)
	{
		rest *= 10;
		(DET)->precision--;
	}
	if ((a = fill_rest(rest, u, &str)) < 0)
	{
		free(str);
		return (-1);
	}
	(DET)->field -= ft_strlen(str) + 1;
	str = fill_zero(str, a, u);
	str = edit_ret(buff, str, detail);
	free((DET)->hexachar);
	return (ft_strlen(str));
}

size_t			u_loop(long double ll, char *buff, long long int prez,
		t_detail **detail)
{
	long long int	u;
	long double		rest;

	u = ll;
	rest = ll - u;
	ll = ll - rest;
	ll += (ll > 0.0) ? 1 : -1;
	(*DET)->precision = prez;
	u = ftoa(ll, buff, *detail);
	return (u);
}

size_t			float_conv(va_list args, t_detail *detail, char *buff)
{
	long long int	u;
	long long int	prez;
	long double		ll;

	(DET)->iffloat = 1;
	if ((DET)->precision == 0)
		(DET)->precision = 6;
	if ((DET)->precision == -1)
		(DET)->precision = 0;
	prez = (DET)->precision;
	if ((DET)->iflong == 2)
		ll = va_arg(args, long double);
	else
		ll = va_arg(args, double);
	u = ftoa(ll, buff, detail);
	if (u == -1)
		u_loop(ll, buff, prez, &detail);
	free(buff);
	return (u);
}
