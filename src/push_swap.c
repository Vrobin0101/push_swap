/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:51:18 by vrobin            #+#    #+#             */
/*   Updated: 2019/09/30 15:43:58 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	set_zero(t_stack *stack)
{
	stack->tab_a = NULL;
	stack->size_a = 0;
	stack->tab_b = NULL;
	stack->size_b = 0;
}

int		main(int nb, char **av)
{
	t_string *string;
	t_stack *stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	set_zero(stack);
	string = initialize_list("start");
	stack->size_a = 0;
	if (nb == 2)
	{
		if (!(stack->tab_a = (int*)malloc(sizeof(int) * stack->size_a)))
			return (0);
		stack->tab_a = string_tab(av[1], stack->tab_a, &stack->size_a);
	}
	else if (nb > 2)
	{
		nb -= 1;
		stack->size_a = nb;
		if (!(stack->tab_a = (int*)malloc(sizeof(int) * nb)))
			return (0);
		stack->tab_a = fill_tab(av, stack->tab_a, nb);
	}
	else
	{
		ft_printf("Error\n");
		return (0);
	}
	algo(stack, string);
}
