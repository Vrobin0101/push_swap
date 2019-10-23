/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:22:11 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/23 16:58:44 by vrobin           ###   ########.fr       */
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
	char					*tmp;

	if (!(str = ft_strnew(BUFF_SIZE)))
		return (NULL);
	if (*f < 0.0)
	{
		*f *= -1;
		str[0] = '-';
	}
	*a = *f;
	u = *f;
	*rest = *f - *a;
	tmp = ft_itoa(*a);
	str = ft_strcat(str, tmp);
	free(tmp);
	i = ft_strlen(str);
	if ((DET)->precision > 0)
		str[i] = '.';
	return (str);
}
