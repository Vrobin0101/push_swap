/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:40:52 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 17:29:30 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void		rotate_back_n(t_stack *stack, t_string *string, int rr, int check)
{
	int c;

	c = check ? stack->size_b : stack->size_a;
	while (rr--)
	{
		if (check == 1)
		{
			stack->tab_b = r_rotate(stack->tab_b, stack->size_b);
			string_push_back(string, initialize_string("rrb"));
		}
		else
		{
			stack->tab_a = r_rotate(stack->tab_a, stack->size_a);
			string_push_back(string, initialize_string("rra"));
		}
	}
}

void		rotate_back(t_stack *stack, t_string *string, int rr, int check)
{
	int	c;

	c = check ? stack->size_b : stack->size_a;
	if (rr > c / 2)
	{
		while (c - rr++)
		{
			if (check == 1)
			{
				stack->tab_b = rotate(stack->tab_b, stack->size_b);
				string_push_back(string, initialize_string("rb"));
			}
			else
				stack->tab_a = rotate(stack->tab_a, stack->size_a);
			string_push_back(string, initialize_string("ra"));
		}
	}
	else
		rotate_back_n(stack, string, rr, check);
}

void		push_rest(t_stack *stack, t_string *string, int check, int p)
{
	while (p)
	{
		if (check == 0)
		{
			string_push_back(string, initialize_string("pa"));
			push(&stack->tab_a, &stack->tab_b, &stack->size_a, &stack->size_b);
		}
		else
		{
			string_push_back(string, initialize_string("pb"));
			push(&stack->tab_b, &stack->tab_a, &stack->size_b, &stack->size_a);
		}
		--p;
	}
}

void		algo(t_stack *stack, t_string *string, int size, int check)
{
	int p;
	int rot;

	rot = 0;
	if (!(test_ret(stack, string, check, size)))
		return ;
	p = check == 0 ? quickswap_a(stack, string, size, &rot)
		: quickswap_b(stack, string, size, &rot);
	if (stack->size_a != 2 || stack->size_b != 2)
		rotate_back(stack, string, rot, check);
	if (size > 1)
	{
		algo(stack, string, size - p, (check == 0 ? 0 : 1));
		algo(stack, string, p, (check == 0 ? 1 : 0));
	}
	push_rest(stack, string, check, p);
}
