/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:50:36 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/22 13:38:46 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		*str_to_tab(char *str, int *tab, int *len)
{
	char	**split;
	int		i;

	split = ft_strsplit(str, ' ');
	if (split[0] == NULL || !(tab = (int*)malloc(sizeof(int) * ft_strlen(str))))
		return (NULL);
	i = 0;
	while (split[i] != NULL)
		i++;
	*len = i;
	i = 0;
	while (i < *len)
	{
		tab[i] = ft_atoi(split[i]);
		i++;
	}
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (tab);
}

int		*fill_tab(char **av, int *tab, int nb)
{
	int i;

	i = 0;
	if (string_arguments(av, nb) == 0)
	{
		ft_putendl("/!/ WATCH OUT /!/");
		ft_putendl("Only the first number of each argument will be taken");
	}
	while (i < nb)
	{
		tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (tab);
}

void	convert_num(t_stack *stack, char **av, int nb)
{
	int i;

	i = 1;
	if (nb == 2)
		stack->tab_a = str_to_tab(av[1], stack->tab_a, &stack->size_a);
	else if (nb > 2)
	{
		nb -= 1;
		stack->size_a = nb;
		if (!(stack->tab_a = (int*)malloc(sizeof(int) * nb)))
			return ;
		stack->tab_a = fill_tab(av, stack->tab_a, nb);
	}
}

void	set_zero(t_stack *stack)
{
	stack->tab_a = NULL;
	stack->size_a = 0;
	stack->tab_b = NULL;
	stack->size_b = 0;
}

void	free_check(t_stack *stack, char *str)
{
	free(stack->tab_a);
	free(stack->tab_b);
	free(stack);
	free(str);
}
