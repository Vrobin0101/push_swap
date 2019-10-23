/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ret.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:43:24 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/23 14:20:41 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int			test_ret_n(t_stack *stack, t_string *string, int check, int size)
{
	if (size == 3)
	{
		if (stack->size_a == 3 && check == 0)
			three_sort_a(stack->tab_a, stack->size_a, string);
		else if (stack->size_b == 3 && check == 1)
			three_sort_b(stack->tab_b, stack->size_b, string);
		else
			return (1);
		return (0);
	}
	return (1);
}

int			test_ret(t_stack *stack, t_string *string, int check, int size)
{
	if (size < 2)
		return (0);
	if (size == 2)
	{
		if (check == 0 && stack->tab_a[0] > stack->tab_a[1])
		{
			stack->tab_a = swap(stack->tab_a, stack->size_a);
			string_push_back(string, initialize_string("sa"));
		}
		if (check == 1 && stack->tab_b[0] < stack->tab_b[1])
		{
			stack->tab_b = swap(stack->tab_b, stack->size_b);
			string_push_back(string, initialize_string("sb"));
		}
		return (0);
	}
	return (test_ret_n(stack, string, check, size));
}
