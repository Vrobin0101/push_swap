/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:51:30 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/15 15:51:38 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker.h"

int		remove_instructions(t_string *string)
{
	int i;

	i = 0;
	while (string->next->next != NULL)
	{
		if (ft_strcmp(string->s, "pb") == 0
				&& ft_strcmp(string->next->s, "pa") == 0)
			return (i);
		else if (ft_strcmp(string->s, "pa") == 0
				&& ft_strcmp(string->next->s, "pb") == 0)
			return (i);
		else if (ft_strcmp(string->s, "ra") == 0
				&& ft_strcmp(string->next->s, "rra") == 0)
			return (i);
		else if (ft_strcmp(string->s, "rra") == 0
				&& ft_strcmp(string->next->s, "ra") == 0)
			return (i);
		else if (ft_strcmp(string->s, "rb") == 0
				&& ft_strcmp(string->next->s, "rrb") == 0)
			return (i);
		else if (ft_strcmp(string->s, "rrb") == 0
				&& ft_strcmp(string->next->s, "rb") == 0)
			return (i);
		i++;
		string = string->next;
	}
	return (0);
}
