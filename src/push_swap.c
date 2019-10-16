/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:51:18 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 18:46:09 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		behavior_push(t_stack *stack, t_string *string)
{
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

int		main(int nb, char **av)
{
	t_string	*string;
	t_stack		*stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	set_zero(stack);
	string = initialize_string("start");
	convert_num(stack, av, nb);
	if (behavior_push(stack, string) == -1)
		return (0);
	algo(stack, string, stack->size_a, 0);
	remove_check(string);
	print_string(string);
}
