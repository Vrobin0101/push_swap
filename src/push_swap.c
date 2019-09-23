/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:51:18 by vrobin            #+#    #+#             */
/*   Updated: 2019/09/19 14:39:06 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		main(int nb, char **av)
{
	int *tab;
	int	len;
	t_string *string;

	string = initialize_list("start");
	len = 0;
	if (nb == 2)
	{
		if (!(tab = (int*)malloc(sizeof(int) * len)))
			return (0);
		tab = string_tab(av[1], tab, &len);
	}
	else if (nb > 2)
	{
		nb -= 1;
		len = nb;
		if (!(tab = (int*)malloc(sizeof(int) * nb)))
			return (0);
		tab = fill_tab(av, tab, nb);
	}
	else
	{
		ft_printf("Error\n");
		return (0);
	}
	algo(tab, len, string);
}
