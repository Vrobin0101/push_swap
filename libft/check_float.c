/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:22:20 by vrobin            #+#    #+#             */
/*   Updated: 2019/06/18 05:39:45 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		bol_nine(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] != '9')
			return (0);
		else
			i++;
	}
	return (1);
}

char	*nega(long double *f, long double *rest, long long int *a,
		t_detail *detail)
{
	long long int			i;
	long long				u;
	char					*str;

	if ((DET)->iflong == 2)
		str = ft_strnew(BUFF_SIZE);
	if ((DET)->iflong == 1)
		str = ft_strnew(BUFF_SIZE / 2);
	else
		str = ft_strnew(32);
	if (*f < 0.0)
	{
		*f *= -1;
		str[0] = '-';
	}
	*a = *f;
	u = *f;
	*rest = *f - *a;
	str = ft_strcat(str, ft_itoa(*a));
	i = ft_strlen(str);
	if ((DET)->precision > 0)
		str[i] = '.';
	return (str);
}
