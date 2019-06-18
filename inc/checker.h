/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 02:40:15 by vrobin            #+#    #+#             */
/*   Updated: 2019/06/18 03:21:28 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
#include "../libft/libft.h"
#include <stdio.h>

void	show_tab(int *tab, int len);
int		*swap(int *tab, int len);
int		*rotate(int *tab, int len);
int		*r_rotate(int *tab, int len);
void	rr(int **tab_a, int **tab_b, int len_a, int len_b);
void	rrr(int **tab_a, int **tab_b, int len_a, int len_b);
void	ss(int **tab_a, int **tab_b, int len_a, int len_b);
void	push(int **dst, int **src, int *len_dst, int *len_src);
#endif
