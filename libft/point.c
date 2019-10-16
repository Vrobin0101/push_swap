/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:46:29 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 18:00:19 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*point_inf(char *buff, char *string, t_detail *detail)
{
	int		i;
	char	*tmp;

	i = 0;
	if ((DET)->precision <= (DET)->strlen)
	{
		if ((DET)->field > (DET)->strlen)
			while (i < (DET)->field - (DET)->strlen - 2)
				buff[i++] = ' ';
		if (!(DET)->minus)
		{
			buff = ft_strcat(buff, "0x");
			buff = ft_strcat(buff, string);
		}
		else
		{
			tmp = buff;
			string = ft_strjoin("0x", string);
			buff = ft_strjoin(string, buff);
			free(tmp);
			free(string);
		}
	}
	return (buff);
}

char			*point_sup(char **buff, char **string, int *i, t_detail *detail)
{
	if ((DET)->field > (DET)->precision && (DET)->field > (DET)->strlen)
		while (*i < (DET)->field - (DET)->precision - 2)
		{
			*buff[*i] = ' ';
			*i += 1;
		}
	if (!(DET)->minus)
	{
		*buff = ft_strcat(*buff, "0x");
		*i += 2;
	}
	if ((DET)->minus)
	{
		*string = ft_strcat(*string, *buff);
		*buff = ft_strcpy(*buff, "0x");
		*i = 2;
	}
	return (*buff);
}
