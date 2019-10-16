/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_ret.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:26:49 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 18:00:02 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*edit_minus(char *buff, char *string, t_detail *detail, char c)
{
	int		j;
	char	*tmp;

	j = 0;
	edit_precision(&buff, &string, &detail);
	if (!(DET)->precision)
	{
		if (ft_strlen(buff) + ft_strlen(string) > BUFF_SIZE)
		{
			tmp = buff;
			buff = ft_strjoin(buff, string);
			free(tmp);
		}
		else
			buff = ft_strcat(buff, string);
	}
	j = (DET)->strlen + (DET)->sign + (DET)->space;
	while (j < (DET)->field)
	{
		clear_buff(&buff, &j, &detail);
		buff[j] = c;
		j++;
	}
	return (buff);
}

char	*edit_normal(char *buff, char *string, t_detail *detail, char c)
{
	int		j;
	char	*tmp;

	j = ((DET)->space) ? 1 : 0;
	if (!(DET)->number && (DET)->precision
			&& (DET)->precision < (DET)->strlen)
		(DET)->strlen = (DET)->precision;
	while (j < (DET)->field - (DET)->strlen)
	{
		clear_buff(&buff, &j, &detail);
		buff[j++] = c;
	}
	edit_precision(&buff, &string, &detail);
	if (!(DET)->precision)
	{
		if (ft_strlen(buff) + ft_strlen(string) > BUFF_SIZE)
		{
			tmp = buff;
			buff = ft_strjoin(buff, string);
			free(tmp);
		}
		else
			buff = ft_strcat(buff, string);
	}
	return (buff);
}

char	*edit_diese(char *buff, char *string, t_detail *detail, char c)
{
	char		*tmp;

	if ((DET)->minus)
		buff = edit_minus(buff, string, detail, c);
	else
		buff = edit_normal(buff, string, detail, c);
	if ((DET)->diese)
	{
		if ((DET)->diese && (DET)->hexa && (DET)->precision > 0)
		{
			string = ft_strdup(buff);
			tmp = string;
			if ((DET)->maj)
				buff = ft_strcpy(buff, "0X");
			else
				buff = ft_strcpy(buff, "0x");
			buff = ft_strcat(buff, string);
			free(tmp);
		}
		else if ((DET)->precision != -1 && (DET)->diese && (DET)->hexa
				&& c == '0')
			buff[1] = (DET)->maj ? 'X' : 'x';
	}
	return (buff);
}

char	*edit_stuff(char *string, t_detail **detail, char *c)
{
	if ((*DET)->precision == -1 && !(*DET)->diese && (*DET)->iffloat == 0)
	{
		string = "";
		(*DET)->precision = 0;
		(*DET)->strlen = 0;
	}
	if ((*DET)->plus && (*DET)->field)
	{
		(*DET)->plus = 0;
		string = ft_strjoin("+", string);
	}
	if ((*DET)->nega && (*DET)->field)
	{
		(*DET)->nega = 0;
		string = ft_strjoin("-", string);
	}
	if ((*DET)->plus || (*DET)->nega)
		(*DET)->strlen += 1;
	if ((*DET)->zero)
	{
		(*DET)->field = (*DET)->zero;
		*c = '0';
	}
	return (string);
}

char	*edit_ret(char *buff, char *string, t_detail *detail)
{
	int		j;
	char	c;
	char	*tmp;

	j = 0;
	c = ' ';
	string = edit_stuff(string, &DET, &c);
	if ((DET)->space)
	{
		buff = ft_strcpy(buff, " ");
		j++;
	}
	buff = edit_diese(buff, string, detail, c);
	if ((DET)->plus || (DET)->nega)
	{
		tmp = buff;
		if ((DET)->plus)
			buff = ft_strjoin("+", buff);
		else
			buff = ft_strjoin("-", buff);
		free(tmp);
	}
	ft_putstr(buff);
	return (buff);
}
