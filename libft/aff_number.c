/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:15:01 by vrobin            #+#    #+#             */
/*   Updated: 2019/06/18 05:49:43 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		check_in(int *j, char **string, t_detail **detail)
{
	(*DET)->number = 1;
	if ((*DET)->plus || (*DET)->nega)
		(*DET)->sign = 1;
	if ((*DET)->precision == -1)
		if (!((*DET)->oct && (*DET)->diese))
			*string = ft_strcpy(*string, "");
	if ((*DET)->sign && (*DET)->space)
		(*DET)->space = 0;
	if ((*DET)->nega)
	{
		if ((*DET)->field && !(*DET)->minus)
			(*DET)->field -= 1;
		(*DET)->space = 0;
		(*DET)->plus = 0;
	}
	*j = 0;
	(*DET)->strlen = ft_strlen(*string);
	if ((*DET)->zero && (*DET)->zero == (*DET)->precision + (*DET)->strlen)
	{
		(*DET)->zero = 0;
		if (!(*DET)->sign)
			(*DET)->space = 1;
	}
	if ((*DET)->precision != -1 && (*DET)->strlen >= (*DET)->precision)
		(*DET)->precision = 0;
}

void		diese(char **string, t_detail **detail)
{
	char	*tmp;

	if (((*DET)->oct || (*DET)->hexa) && (!((*DET)->zero || (*DET)->precision))
			&& (*DET)->diese && ft_strcmp(*string, "0") != 0)
	{
		tmp = *string;
		if ((*DET)->oct)
			*string = ft_strjoin("0", *string);
		if ((*DET)->hexa)
		{
			if ((*DET)->maj)
				*string = ft_strjoin("0X", *string);
			else if ((*DET)->hexa && !(*DET)->maj)
				*string = ft_strjoin("0x", *string);
			(*DET)->strlen += 1;
		}
		(*DET)->strlen += 1;
		if ((*DET)->precision)
			(*DET)->precision += 2;
		(*DET)->diese = 0;
	}
}

size_t		aff_number(char *buff, char *string, t_detail *detail)
{
	int		j;
	char	*tmp;
	size_t	u;

	check_in(&j, &string, &detail);
	diese(&string, &detail);
	if ((DET)->precision > (DET)->strlen)
	{
		while (j < (DET)->precision - (DET)->strlen)
			buff[j++] = '0';
		tmp = string;
		string = ft_strjoin(buff, string);
		buff = ft_strcpy(buff, "");
		free(tmp);
	}
	if ((DET)->precision > (DET)->strlen)
		(DET)->strlen = (DET)->precision + (DET)->sign;
	buff = edit_ret(buff, string, detail);
	u = ft_strlen(buff);
	free(string);
	return (u);
}
