/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:41:04 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/26 11:43:11 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				check_next(char *str)
{
	if ((ft_strncmp(str, "pa", 2) == 0)
			|| (ft_strncmp(str, "pb", 2) == 0)
			|| (ft_strncmp(str, "sa", 2) == 0)
			|| (ft_strncmp(str, "sb", 2) == 0)
			|| (ft_strncmp(str, "ss", 2) == 0)
			|| (ft_strncmp(str, "ra", 2) == 0)
			|| (ft_strncmp(str, "rb", 2) == 0)
			|| (ft_strncmp(str, "rra", 3) == 0)
			|| (ft_strncmp(str, "rrb", 3) == 0)
			|| (ft_strncmp(str, "rr", 2) == 0)
			|| (ft_strncmp(str, "sha", 3) == 0)
			|| (ft_strncmp(str, "shb", 3) == 0)
			|| (ft_strncmp(str, "shh", 3) == 0))
		return (1);
	return (0);
}
