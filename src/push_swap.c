/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:51:18 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/22 13:44:28 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		behavior_push(t_stack *stack, t_string *string)
{
	if (stack->tab_a == NULL)
	{
		ft_putendl("Error");
		return (-1);
	}
	if (bol_check(stack->tab_a, stack->size_a, 1) == 1)
		return (-1);
	if (stack->size_a == 3)
	{
		three_sort_a(stack->tab_a, stack->size_a, string);
		print_string(string);
		return (-1);
	}
	return (1);
}

void	free_all(t_stack *stack, t_string *string)
{
	free(stack->tab_a);
	free(stack->tab_b);
	free(stack);
	string_clear(string);
}

int		main(int nb, char **av)
{
	t_string	*string;
	t_stack		*stack;

	if (nb == 1 || !(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	set_zero(stack);
	string = initialize_string("start");
	if (nb > 1 && check_multiples_digits(av, nb) == 0)
	{
		free_all(stack, string);
		return (0);
	}
	convert_num(stack, av, nb);
	if (check_duplicate(stack->tab_a, stack->size_a) == 0
			|| behavior_push(stack, string) == -1)
	{
		free_all(stack, string);
		return (0);
	}
	if (!(stack->tab_b = (int*)malloc(sizeof(int) * stack->size_a)))
		return (0);
	algo(stack, string, stack->size_a, 0);
	remove_check(string);
	print_string(string);
	free_all(stack, string);
}
