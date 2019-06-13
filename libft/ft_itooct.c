/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itooct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:27:51 by vrobin            #+#    #+#             */
/*   Updated: 2019/06/12 02:08:06 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_itooct(unsigned long long nb)
{
	unsigned long long	octnbr;
	unsigned long long	i;

	octnbr = 0;
	i = 1;
	while (nb > 0)
	{
		octnbr += (nb % 8) * i;
		nb /= 8;
		i *= 10;
	}
	return (octnbr);
}
