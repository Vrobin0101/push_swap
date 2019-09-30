/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:35:19 by vrobin            #+#    #+#             */
/*   Updated: 2019/09/30 13:42:17 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		*string_tab(char *str, int *tab, int *len)
{
	char **split;
	int	 i;

	split = ft_strsplit(str, ' ');
	i = 0;
	while (split[i] != NULL)
		i++;
	*len = i;
	if (!(tab = (int*)malloc(sizeof(int) * *len)))
		return (0);
	i = 0;
	while (i < *len)
	{
		tab[i] = ft_atoi(split[i]);
		if (ft_atoi(split[i]) > INT_MAX || ft_atoi(split[i]) < INT_MIN)
			return (NULL);
		i++;
	}
	return (tab);
}
