/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:15:01 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/23 09:19:38 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		check2(int *j, char **string, t_detail **detail)
{
	if ((*DET)->field && (*DET)->plus && !(*DET)->minus
			&& (!(*DET)->precision || (*DET)->precision < (*DET)->strlen))
		(*DET)->field -= 1;
	*j = 0;
	(*DET)->strlen = ft_strlen(*string);
	if ((*DET)->zero && (*DET)->zero == (*DET)->precision + (*DET)->strlen)
		(*DET)->zero = 0;
	if (!(*DET)->diese && (*DET)->precision != -1
			&& (*DET)->precision != 0 && (*DET)->strlen >= (*DET)->precision)
	{
		if ((*DET)->field && (*DET)->plus && !(*DET)->minus)
			(*DET)->field -= (*DET)->plus;
		if ((*DET)->zero)
		{
			(*DET)->field = (*DET)->zero - (*DET)->sign;
			(*DET)->zero = 0;
		}
		(*DET)->precision = 0;
	}
}

void		check1(int *j, char **string, t_detail **detail)
{
	if (!(*DET)->oct && !(*DET)->hexa && !(*DET)->field
			&& (int)ft_strlen(*string) + (*DET)->precision == (*DET)->zero)
		(*DET)->field = (*DET)->zero;
	(*DET)->number = 1;
	if ((*DET)->plus || (*DET)->nega)
		(*DET)->sign = 1;
	if (!(*DET)->diese && (*DET)->precision == -1
			&& ft_strcmp(*string, "0") == 0)
		if (!((*DET)->oct && (*DET)->diese))
			*string = ft_strcpy(*string, "");
	if (((*DET)->sign || (*DET)->plus) && (*DET)->space)
		(*DET)->space = 0;
	if ((*DET)->nega)
	{
		if ((*DET)->field && !(*DET)->minus)
			(*DET)->field -= 1;
		(*DET)->space = 0;
		(*DET)->plus = 0;
	}
	check2(j, string, detail);
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
		free(tmp);
	}
}

void		prez_diese(char **string, t_detail **detail)
{
	diese(string, detail);
	if (!(*DET)->diese && (*DET)->zero && (*DET)->precision == -1)
	{
		if (!(*DET)->field && ft_strcmp(*string, "0") == 0)
			*string = ft_strcpy(*string, "");
		(*DET)->field = (*DET)->zero - (*DET)->sign;
		(*DET)->zero = 0;
		(*DET)->precision = 0;
	}
	else if (!(*DET)->diese && (*DET)->zero && (*DET)->precision)
	{
		(*DET)->field = (*DET)->zero - (*DET)->nega;
		(*DET)->zero = 0;
	}
}

size_t		aff_number(char *buff, char *string, t_detail *detail)
{
	int		j;
	char	*tmp;
	size_t	u;

	(DET)->space = (DET)->plus && (DET)->space ? 0 : (DET)->space;
	(DET)->strlen += (DET)->nega;
	check1(&j, &string, &detail);
	prez_diese(&string, &detail);
	if ((DET)->precision > (DET)->strlen && (DET)->precision != -1)
	{
		while (j < (DET)->precision - (DET)->strlen)
			buff[j++] = '0';
		tmp = string;
		string = ft_strjoin(buff, string);
		buff = ft_strcpy(buff, "");
		free(tmp);
	}
	if ((DET)->precision > (DET)->strlen)
		(DET)->strlen = (DET)->precision + (DET)->plus;
	buff = edit_ret(buff, string, detail);
	u = ft_strlen(buff);
	free(string);
	free(buff);
	return (u);
}
