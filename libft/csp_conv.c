/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:49:35 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 18:01:31 by vrobin           ###   ########.fr       */
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
	if (!(string = (char*)malloc(sizeof(char) * 2)))
		return (0);
	string[0] = c;
	string[1] = '\0';
	if (c == 0)
		return (ifc_null(buff, string, detail));
	buff = edit_ret(buff, string, detail);
	i = ft_strlen(buff);
	free(string);
	free(buff);
	return (i);
}

size_t			ifc_null(char *buff, char *string, t_detail *detail)
{
	int check;

	check = 0;
	if ((DET)->minus)
	{
		ft_putchar(0);
		(DET)->minus = 0;
		check = 1;
	}
	buff = edit_ret(buff, string, detail);
	if (!check)
		ft_putchar(0);
	free(string);
	free(buff);
	if ((DET)->field)
		return ((DET)->field);
	return (1);
}

size_t			aff_string(va_list args, t_detail *detail, char *buff)
{
	int			i;
	char		*string;
	char		*tmp;

	string = va_arg(args, char*);
	tmp = NULL;
	(DET)->strlen = ft_strlen(string);
	if ((DET)->precision > (DET)->strlen && (DET)->field && !(DET)->minus)
		if ((DET)->precision < (DET)->strlen)
		{
			(DET)->field += (DET)->precision - (DET)->strlen;
		}
	if (string == NULL)
	{
		string = ft_strdup("(null)");
		tmp = string;
		(DET)->strlen = ft_strlen(string);
	}
	if ((DET)->minus && (DET)->precision > (DET)->strlen)
		(DET)->precision = 0;
	buff = edit_ret(buff, string, detail);
	i = ft_strlen(buff);
	free(tmp);
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
	string = ft_strdup(tmp);
	(DET)->strlen = ft_strlen(string);
	buff = edit_point(buff, string, detail);
	free(string);
	free(tmp);
	ft_putstr(buff);
	u = ft_strlen(buff);
	free(buff);
	return (u);
}

char			*edit_point(char *buff, char *string, t_detail *detail)
{
	int	i;

	i = 0;
	buff = point_inf(buff, string, detail);
	if ((DET)->precision > (DET)->strlen)
	{
		buff = point_sup(&buff, &string, &i, detail);
		while ((DET)->precision - (DET)->strlen)
		{
			buff[i] = '0';
			i++;
			(DET)->precision--;
		}
		buff = ft_strcat(buff, string);
	}
	return (buff);
}
