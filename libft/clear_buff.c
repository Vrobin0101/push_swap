/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_buff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 05:00:26 by vrobin            #+#    #+#             */
/*   Updated: 2019/06/18 05:39:54 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clear_buff(char **buff, int *j, t_detail **detail)
{
	if (*j >= BUFF_SIZE - 1)
	{
		(*DET)->len += *j;
		(*DET)->overbuff = 1;
		ft_putstr(*buff);
		free(*buff);
		*buff = ft_strnew(BUFF_SIZE);
		(*DET)->field -= *j;
		*j = 0;
	}
}
