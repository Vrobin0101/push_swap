/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:41:46 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/15 17:58:10 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

t_string	create_string(char *p_s)
{
	t_string result;

	result.s = ft_strdup(p_s);
	result.next = NULL;
	return (result);
}

t_string	*initialize_string(char *p_s)
{
	t_string *result;

	if (!(result = (t_string*)malloc(sizeof(t_string))))
		return (NULL);

	*result = create_string(p_s);
	return (result);
}

void	string_push_back(t_string *src, t_string *to_add)
{
	while (src->next != NULL)
		src = src->next;
	src->next = to_add;
}
