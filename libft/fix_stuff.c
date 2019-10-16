/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:02:57 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 18:01:15 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	edit_precision(char **buff, char **string, t_detail **detail)
{
	char	*tmp;

	if ((*DET)->precision)
	{
		if ((*DET)->precision > BUFF_SIZE)
		{
			tmp = *buff;
			*buff = ft_strnjoin(*buff, *string,
					(*DET)->precision + (*DET)->sign);
			free(tmp);
		}
		else
			*buff = ft_strncat(*buff, *string,
					(*DET)->precision + (*DET)->sign);
		if ((*DET)->minus && ft_strcmp("", *string) != 0
				&& ft_strcmp("NULL", *string) != 0)
			(*DET)->strlen = (*DET)->precision;
	}
}

size_t	fix_stuffx(unsigned long long ll, char *buff, t_detail *detail)
{
	char	*tmp;

	if ((DET)->precision != 0 && (DET)->zero)
	{
		if (ll == 0)
			(DET)->diese = 0;
		(DET)->field = (DET)->zero;
		(DET)->zero = 0;
	}
	if ((DET)->minus && (DET)->zero)
		(DET)->zero = 0;
	if (ll >= ULONG_MAX)
		tmp = ft_llutoa_base(ll, (DET)->hexachar);
	else
		tmp = ft_itoa_base(ll, (DET)->hexachar);
	(DET)->strlen = ft_strlen(tmp);
	if (ll == 0 && (DET)->diese && ((DET)->zero >= (DET)->strlen
				|| (DET)->precision >= (DET)->strlen))
		(DET)->diese = 0;
	if ((DET)->zero < (DET)->strlen)
		(DET)->zero = 0;
	if (ll != 0 && ((DET)->precision == -1 || (DET)->precision < (DET)->strlen))
		(DET)->precision = 0;
	ll = aff_number(buff, tmp, detail);
	return (ll);
}

size_t	fix_stuffo(unsigned long long ll, char *buff, t_detail *detail)
{
	char					*tmp;

	if ((DET)->minus && (DET)->zero)
		(DET)->zero = 0;
	if (ll >= ULONG_MAX)
		tmp = ft_llutoa_base(ll, "01234567");
	else
		tmp = ft_itoa_base(ll, "01234567");
	(DET)->strlen = ft_strlen(tmp);
	if ((DET)->zero < (DET)->strlen)
		(DET)->zero = 0;
	if (ll != 0 && ((DET)->precision == -1 || (DET)->precision < (DET)->strlen))
		(DET)->precision = 0;
	ll = aff_number(buff, tmp, detail);
	return (ll);
}
