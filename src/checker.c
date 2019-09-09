/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 02:54:49 by vrobin            #+#    #+#             */
/*   Updated: 2019/09/09 16:45:15 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		main(int nb, char **av)
{
	int		*tab1;
	int		*tab2;
	int		len1;
	int		len2;
	int		check;
	char	*str;

	check = 0;
	tab2 = NULL;
	len2 = 0;
	if (nb == 2)
	{
		if (!(tab1 = (int*)malloc(sizeof(int) * ft_strlen(av[1]))))
			return (0);
		tab1 = string_tab(av[1], tab1, &len1);
	}
	else if (nb > 2)
	{
		nb -= 1;
		len1 = nb;
		if (!(tab1 = (int*)malloc(sizeof(int) * nb)))
			return (0);
		if (!(tab1 = fill_tab(av, tab1, nb)))
		{
			ft_putendl("Error");
			return (-1);
		}
	}
	while (get_next_line(0, &str) > 0)
	{
		check = 0;
		if (ft_strcmp(str, "pa") == 0)
		{
			push(&tab1, &tab2, &len1, &len2);
			check = 1;
		}
		if (ft_strcmp(str, "pb") == 0)
		{
			push(&tab2, &tab1, &len2, &len1);
			check = 1;
		}
		if (ft_strcmp(str, "sa") == 0)
		{
			tab1 = swap(tab1, len1);
			check = 1;
		}
		if (ft_strcmp(str, "sb") == 0)
		{
			tab2 = swap(tab2, len2);
			check = 1;
		}
		if (ft_strcmp(str, "ra") == 0)
		{
			tab1 = rotate(tab1, len1);
			check = 1;
		}
		if (ft_strcmp(str, "rb") == 0)
		{
			tab2 = rotate(tab2, len2);
			check = 1;
		}
		if (ft_strcmp(str, "rr") == 0)
		{
			rr(&tab1, &tab2, len1, len2);
			check = 1;
		}
		if (ft_strcmp(str, "rra") == 0)
		{
			tab1 = r_rotate(tab1, len1);
			check = 1;
		}
		if (ft_strcmp(str, "rrb") == 0)
		{
			tab2 = r_rotate(tab2, len2);
			check = 1;
		}
		if (ft_strcmp(str, "rrr") == 0)
		{
			rrr(&tab1, &tab2, len1, len2);
			check = 1;
		}
		if (ft_strcmp(str, "sha") == 0)
		{
			ft_printf("%t", tab1, len1);
			check = 1;
		}
		if (ft_strcmp(str, "shb") == 0)
		{
			ft_printf("%t", tab2, len2);
			check = 1;
		}
		else if (check == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		ft_strdel(&str);
	}
	checkn(tab1, len1);
	return (0);
}
