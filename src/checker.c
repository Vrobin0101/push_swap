/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 02:54:49 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 15:10:39 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	checker_end(int *tab, int len1, int len2)
{
	int i;

	i = 0;
	if (len2)
	{
		ft_putendl("KO");
		return ;
	}
	while (i < len1 - 1)
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

int		behavior_check(t_stack *stack)
{
	if (stack->tab_a == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (stack->size_a == 1)
		return (0);
	return (1);
}

int		parsing_first(t_stack *stack, char *str)
{
	if (ft_strcmp(str, "pa") == 0)
		push(&stack->tab_a, &stack->tab_b, &stack->size_a, &stack->size_b);
	else if (ft_strcmp(str, "pb") == 0)
		push(&stack->tab_b, &stack->tab_a, &stack->size_b, &stack->size_a);
	else if (ft_strcmp(str, "sa") == 0)
		stack->tab_a = swap(stack->tab_a, stack->size_a);
	else if (ft_strcmp(str, "sb") == 0)
		stack->tab_b = swap(stack->tab_b, stack->size_b);
	else if (ft_strcmp(str, "ss") == 0)
		ss(&stack->tab_a, &stack->tab_b, stack->size_a, stack->size_b);
	else if (ft_strcmp(str, "ra") == 0)
		stack->tab_a = rotate(stack->tab_a, stack->size_a);
	else if (ft_strcmp(str, "rb") == 0)
		stack->tab_b = rotate(stack->tab_b, stack->size_b);
	else if (ft_strcmp(str, "rra") == 0)
		stack->tab_a = r_rotate(stack->tab_a, stack->size_a);
	else if (ft_strcmp(str, "rrb") == 0)
		stack->tab_b = r_rotate(stack->tab_b, stack->size_b);
	else
		return (0);
	return (1);
}

int		parsing_second(t_stack *stack, char *str)
{
	if (ft_strcmp(str, "rrr") == 0)
		rrr(&stack->tab_a, &stack->tab_b, stack->size_a, stack->size_b);
	else if (ft_strcmp(str, "rr") == 0)
		rr(&stack->tab_a, &stack->tab_b, stack->size_a, stack->size_b);
	else if (ft_strcmp(str, "sha") == 0)
		show_tab(stack->tab_a, stack->size_a, 1);
	else if (ft_strcmp(str, "shb") == 0)
		show_tab(stack->tab_b, stack->size_b, 0);
	else if (ft_strcmp(str, "shh") == 0)
		show_all(stack->tab_a, stack->tab_b, stack->size_a, stack->size_b);
	else
		return (0);
	return (1);
}

int		main(int nb, char **av)
{
	t_stack *stack;
	int		check;
	char	*str;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	set_zero(stack);
	check = 0;
	convert_num(stack, av, nb);
	if (!behavior_check(stack))
	{
		return (0);
	}
	while (get_next_line(0, &str) > 0)
	{
		if (parsing_first(stack, str) == 0 && parsing_second(stack, str) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		ft_strdel(&str);
	}
	checker_end(stack->tab_a, stack->size_a, stack->size_b);
	return (0);
}
