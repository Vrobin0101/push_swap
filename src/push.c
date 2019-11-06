/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:09:49 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/29 14:26:18 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	move_one(int **src, int *len_src)
{
	int i;

	i = 0;
	while (i < *len_src -1)
	{
		src[0][i] = src[0][i + 1];
		i++;
	}
	*len_src -= 1;
}

void	push(int **dst, int **src, int *len_dst, int *len_src)
{
	int j;
	int nb;
	int i;

	j = 0;
	i = 0;
	if (*len_src > 0)
	{
		nb = src[0][0];
		while (j < *len_dst + 1)
		{
			i = dst[0][j];
			dst[0][j] = nb;
			nb = i;
			j++;
		}
		move_one(src, len_src);
		*len_dst += 1;
	}
}
