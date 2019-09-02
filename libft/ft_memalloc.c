/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:18:46 by spuisais          #+#    #+#             */
/*   Updated: 2019/09/02 14:50:06 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t *dest;

	if (!(dest = (size_t *)malloc(sizeof(size_t) * size)))
		return (NULL);
	ft_memset(dest, 0, size);
	return (dest);
}
