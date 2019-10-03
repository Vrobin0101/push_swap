/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:17:01 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/03 16:52:20 by vrobin           ###   ########.fr       */
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

t_chunk	create_chunk(int p_i)
{
	t_chunk result;

	result.size = p_i;
	result.next = NULL;
	return (result);
}


t_chunk	*initialize_chunk(int p_i)
{
	t_chunk *result;

	if (!(result = (t_chunk*)malloc(sizeof(t_chunk))))
		return (NULL);
	*result = create_chunk(p_i);
	return (result);
}

void	free_chunk(t_chunk *to_delete)
{
	to_delete->next = NULL;
	free(to_delete);
}

void	chunk_push_back(t_chunk *src, t_chunk *to_add)
{
	while (src->next != NULL)
		src = src->next;
	src->next = to_add;
}

t_chunk                  *rev_chunk(t_chunk **begin)
{
	t_chunk          *prev;
	t_chunk          *cur;
	t_chunk          *next;
	prev = NULL;
	next = NULL;
	cur = *begin;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*begin = prev;
	return (*begin);
}


void	chunk_remove(t_chunk *src, size_t index)
{
	size_t i;
	t_chunk *tmp;

	i = 0;
	while (src->next != NULL && index > i + 1)
	{
		src = src->next;
		i++;
	}
	tmp = src->next;
	if (tmp->next != NULL)
		tmp = tmp->next;
	free_chunk(src->next);
	src->next = tmp;
}

void	chunk_clear(t_chunk *to_clear)
{
	t_chunk *tmp;

	while (to_clear != NULL)
	{
		tmp = to_clear->next;
		free_chunk(to_clear);
		to_clear = tmp;
	}
}

void	print_chunk(t_chunk *src)
{
	int i;

	i = 0;
	while (src != NULL)
	{
		ft_printf("%d ", src->size);
		src = src->next;
		i++;
	}
	ft_putchar('\n');
}
