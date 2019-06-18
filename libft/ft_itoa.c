/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 11:30:00 by vrobin            #+#    #+#             */
/*   Updated: 2019/06/18 05:35:29 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(long long n)
{
	long long i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(long long n)
{
	char				*str;
	long long			len;
	unsigned long long	nb;

	len = ft_intlen(n);
	nb = n;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	str[len--] = '\0';
	if (nb == 0)
		str[len--] = '0';
	if (n < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb != 0)
	{
		str[len--] = (nb % 10 > 9) ? (nb % 10 - 10) : nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
