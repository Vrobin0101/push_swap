/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bol_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:36:35 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/23 16:49:50 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		bol_check(int *tab, int len, int check)
{
	int i;

	i = 0;
	if (check == 1)
	{
		while (i < len - 1)
		{
			if (tab[i + 1] < tab[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		while (i < len - 1)
		{
			if (tab[i + 1] > tab[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	set_zero(t_stack *stack)
{
	stack->tab_a = NULL;
	stack->size_a = 0;
	stack->tab_b = NULL;
	stack->size_b = 0;
}
