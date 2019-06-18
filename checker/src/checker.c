/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 02:54:49 by vrobin            #+#    #+#             */
/*   Updated: 2019/06/18 04:05:45 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker.h"

void	show_tab(int *tab, int len)
{
	int i;

	i = 0;
	ft_putchar('\n');
	while (i < len)
		ft_putendl(ft_itoa(tab[i++]));
	ft_putchar('\n');
}

int		*fill_tab(char **av, int *tab, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (tab);
}

void	check(int *tab, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i + 1] < tab[i])
		{
			ft_putendl("KO");
			return ;
		}
		i++;
	}
	ft_putendl("OK");
}

int		main(int nb, char **av)
{
	int *tab1;
	int	*tab2;
	int	len1;
	int	len2;
	char *str;

	len2 = 0;
	tab2 = NULL;
	nb -= 1;
	len1 = nb;
	if (!(tab1 = (int*)malloc(sizeof(int) * nb)))
		return (0);
	tab1 = fill_tab(av, tab1, nb);
	show_tab(tab1, len1);
	show_tab(tab2, len2);
	str = ft_strnew(10);
	while (ft_strcmp(str, "\n") != 0)
	{
		str = ft_strnew(10);
		read(0, str, 10);
		if (ft_strcmp(str, "pa\n") == 0)
			push(&tab1, &tab2, &len1, &len2);
		if (ft_strcmp(str, "pb\n") == 0)
			push(&tab2, &tab1, &len2, &len1);
		if (ft_strcmp(str, "sa\n") == 0)
			tab1 = swap(tab1, len1);
		if (ft_strcmp(str, "sb\n") == 0)
			tab2 = swap(tab2, len2);
		if (ft_strcmp(str, "ra\n") == 0)
			tab1 = rotate(tab1, len1);
		if (ft_strcmp(str, "rb\n") == 0)
			tab2 = rotate(tab2, len2);
		if (ft_strcmp(str, "rr\n") == 0)
			rr(&tab1, &tab2, len1, len2);
		if (ft_strcmp(str, "rra\n") == 0)
			tab1 = r_rotate(tab1, len1);
		if (ft_strcmp(str, "rrb\n") == 0)
			tab2 = r_rotate(tab2, len2);
		if (ft_strcmp(str, "rrr\n") == 0)
			rrr(&tab1, &tab2, len1, len2);
		if (ft_strcmp(str, "sha\n") == 0)
			show_tab(tab1, len1);
		if (ft_strcmp(str, "shb\n") == 0)
			show_tab(tab2, len2);
	}
	check(tab1, len1);
	return (0);
}
