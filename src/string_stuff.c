/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:42:21 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 14:32:13 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	free_string(t_string *to_delete)
{
	free(to_delete->s);
	to_delete->next = NULL;
	free(to_delete);
}

void	string_remove(t_string *src, size_t index)
{
	size_t		i;
	t_string	*tmp;

	i = 0;
	while (src->next != NULL && index > i + 1)
	{
		src = src->next;
		i++;
	}
	tmp = src->next;
	if (tmp->next != NULL)
		tmp = tmp->next;
	free_string(src->next);
	src->next = tmp;
}

void	string_clear(t_string *to_clear)
{
	t_string *tmp;

	while (to_clear != NULL)
	{
		tmp = to_clear->next;
		free_string(to_clear);
		to_clear = tmp;
	}
}

void	print_string(t_string *src)
{
	int i;

	i = 0;
	while (src != NULL)
	{
		if (i != 0 && ft_strcmp(src->s, "") != 0)
			ft_printf("%s\n", src->s);
		src = src->next;
		i++;
	}
}
