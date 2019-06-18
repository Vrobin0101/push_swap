/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:49:35 by vrobin            #+#    #+#             */
/*   Updated: 2019/06/18 05:40:04 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			aff_char(va_list args, t_detail *detail, char *buff)
{
	int			i;
	char		c;
	char		*string;

	(DET)->space = 0;
	c = (char)va_arg(args, int);
	(DET)->strlen = 1;
	if (!(string = (char*)malloc(sizeof(char) * 1)))
		return (0);
	string[0] = c;
	if (c == 0)
	{
		free(string);
		string = ft_strdup("^@");
		buff = edit_ret(buff, string, detail);
		free(string);
		free(buff);
		return (ft_strlen(buff) - 1);
	}
	buff = edit_ret(buff, string, detail);
	free(string);
	i = ft_strlen(buff);
	free(buff);
	return (i);
}

size_t			aff_string(va_list args, t_detail *detail, char *buff)
{
	int			i;
	char		*string;

	string = va_arg(args, char*);
	(DET)->strlen = ft_strlen(string);
	if ((DET)->precision > (DET)->strlen && (DET)->field && !(DET)->minus)
		if ((DET)->precision < (DET)->strlen)
			(DET)->field += (DET)->precision - (DET)->strlen;
	if (string == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	buff = edit_ret(buff, string, detail);
	i = ft_strlen(buff);
	free(buff);
	return (i);
}

size_t			aff_pointer(va_list args, t_detail *detail, char *buff)
{
	long long	u;
	void		*p;
	char		*string;
	char		*tmp;

	if ((DET)->precision == -1)
	{
		ft_putstr("0x");
		return (2);
	}
	(DET)->space = 0;
	p = va_arg(args, void*);
	u = (long long)(p);
	tmp = ft_itoa_base(u, "0123456789abcdef");
	string = ft_strdup("0x");
	string = ft_strcat(string, tmp);
	(DET)->strlen = ft_strlen(string);
	if ((DET)->precision > (DET)->strlen && (DET)->field && !(DET)->minus)
		(DET)->field += (DET)->precision - (DET)->strlen;
	buff = edit_ret(buff, string, detail);
	free(string);
	free(tmp);
	u = ft_strlen(buff);
	free(buff);
	return (u);
}
