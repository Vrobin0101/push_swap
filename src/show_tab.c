/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:33:44 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 15:07:37 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	show_tab(int *tab, int len, int d)
{
	int i;

	i = 0;
	ft_printf("//////////////////////////////////////////////////\n");
	if (d == 1)
		ft_printf("[ A ]");
	else
		ft_printf("[ B ]");
	ft_printf("\n%t", tab, len);
	ft_printf("//////////////////////////////////////////////////\n");
}

void	show_all(int *tab1, int *tab2, int len1, int len2)
{
	show_tab(tab1, len1, 1);
	ft_putchar('\n');
	show_tab(tab2, len2, 2);
}
