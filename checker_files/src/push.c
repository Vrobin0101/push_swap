/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 02:46:07 by vrobin            #+#    #+#             */
/*   Updated: 2019/06/18 04:37:46 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker.h"

void	push(int **dst, int **src, int *len_dst, int *len_src)
{
	int	*new_dst;
	int	i;
	int j;

	j = 0;
	i = 0;
	if (*len_src > 0)
	{
		new_dst = (int*)malloc(sizeof(int) * (*len_dst + 2));
		new_dst[*len_dst + 1] = '\0';
		new_dst[i] = *src[i];
		i++;
		while (j < *len_dst)
		{
			new_dst[i] = dst[0][j];
			i++;
			j++;
		}
		++*src;
		*len_src -= 1;
		*len_dst += 1;
		*dst = new_dst;
	}
}
