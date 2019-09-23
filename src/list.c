/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:17:01 by vrobin            #+#    #+#             */
/*   Updated: 2019/09/20 11:28:41 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

t_string	create_list(char *p_s)
{
	t_string result;

	result.s = ft_strdup(p_s);
	result.next = NULL;
	return (result);
}

t_string	*initialize_list(char *p_s)
{
	t_string *result;

	if (!(result = (t_string*)malloc(sizeof(t_string))))
		return (NULL);

	*result = create_list(p_s);
	return (result);
}

void	free_list(t_string *to_delete)
{
	free(to_delete->s);
	to_delete->next = NULL;
	free(to_delete);
}

void	list_push_back(t_string *src, t_string *to_add)
{
	while (src->next != NULL)
		src = src->next;
	src->next = to_add;
}

void	list_remove(t_string *src, size_t index)
{
	size_t i;
	t_string *tmp;

	i = 0;
	while (src->next != NULL && index > i + 1)
	{
		src = src->next;
		i++;
	}
	tmp = src->next;
	if (tmp->next != NULL)
		tmp = tmp->next;
	free_list(src->next);
	src->next = tmp;
}

void	list_clear(t_string *to_clear)
{
	t_string *tmp;

	while (to_clear != NULL)
	{
		tmp = to_clear->next;
		free_list(to_clear);
		to_clear = tmp;
	}
}

void	print_list(t_string *src)
{
	int i;

	i = 0;
	while (src != NULL)
	{
		if (i != 0)
			ft_putendl(src->s);
		src = src->next;
		i++;
	}
}
