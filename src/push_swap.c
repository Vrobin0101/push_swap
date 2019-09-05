/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:51:18 by vrobin            #+#    #+#             */
/*   Updated: 2019/09/05 16:35:07 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		main(int nb, char **av)
{
	int *tab;
	int	len;

	nb -= 1;
	len = nb;
	if (!(tab = (int*)malloc(sizeof(int) * nb)))
				return (0);
	tab = fill_tab(av, tab, nb);
	algo(tab, len);
}
