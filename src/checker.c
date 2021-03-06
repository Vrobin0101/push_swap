/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 02:54:49 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/26 12:12:47 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	checker_end(t_stack *stack)
{
	int i;

	i = 0;
	if (stack->size_b)
	{
		ft_putendl("KO");
		return ;
	}
	while (i < stack->size_a - 1)
	{
		if (stack->tab_a[i + 1] < stack->tab_a[i])
		{
			ft_putendl("KO");
			return ;
		}
		i++;
	}
	ft_putendl("OK");
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

void	check_gnl(t_stack *stack)
{
	int		check;
	char	*str;

	check = 0;
	while ((check = get_next_line(0, &str)) > 0)
	{
		if (ft_strcmp(str, "") == 0)
			break ;
		if (parsing_first(stack, str) == 0 && parsing_second(stack, str) == 0)
		{
			ft_printf("Error\n");
			free_check(stack, str);
			return ;
		}
		ft_strdel(&str);
	}
	if (check != -2)
		checker_end(stack);
	else
		ft_putendl("Error");
	free_check(stack, str);
}

int		main(int nb, char **av)
{
	t_stack		*stack;

	if (nb == 1 || !(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (1);
	set_zero(stack);
	convert_num(stack, av, nb);
	if (nb > 1 && check_multiples_digits(av, nb) == 0)
	{
		free(stack->tab_a);
		free(stack);
		return (2);
	}
	if (!(stack->tab_b = (int*)malloc(sizeof(int) * stack->size_a)) ||
			check_duplicate(stack->tab_a, stack->size_a) == 0
			|| !behavior_check(stack))
	{
		free(stack->tab_a);
		free(stack->tab_b);
		free(stack);
		return (3);
	}
	check_gnl(stack);
	return (0);
}
