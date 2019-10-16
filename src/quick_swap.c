/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:14:05 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 11:16:32 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int			quickswap_a(t_stack *stack, t_string *string, int len, int *r)
{
	int med;
	int p;
	int i;

	p = 0;
	i = 0;
	med = get_med(stack->tab_a, len);
	while (i < len)
	{
		if (stack->tab_a[0] < med)
		{
			string_push_back(string, initialize_string("pb"));
			push(&stack->tab_b, &stack->tab_a, &stack->size_b, &stack->size_a);
			p++;
		}
		else
		{
			string_push_back(string, initialize_string("ra"));
			stack->tab_a = rotate(stack->tab_a, stack->size_a);
			(*r)++;
		}
		i++;
	}
	return (p);
}

int			quickswap_b(t_stack *stack, t_string *string, int len, int *r)
{
	int med;
	int p;
	int i;

	p = 0;
	i = 0;
	med = get_med(stack->tab_b, len);
	while (i < len)
	{
		if (stack->tab_b[0] >= med)
		{
			string_push_back(string, initialize_string("pa"));
			push(&stack->tab_a, &stack->tab_b, &stack->size_a, &stack->size_b);
			p++;
		}
		else
		{
			string_push_back(string, initialize_string("rb"));
			stack->tab_b = rotate(stack->tab_b, stack->size_b);
			(*r)++;
		}
		i++;
	}
	return (p);
}
