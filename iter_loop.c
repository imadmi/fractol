/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:07:24 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/03 18:24:02 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter_loop_mandelbrot(t_fract *t)
{
	while (t->iter < t->max)
	{
		t->xtmp = t->x * t->x - t->y * t->y;
		t->ytmp = 2 * t->x * t->y;
		t->x = t->xtmp + t->x_zero;
		t->y = t->ytmp + t->y_zero;
		if (t->x * t->x + t->y * t->y > 4)
			break ;
		t->iter++;
	}
}

void	looping(t_fract *t)
{
	if (ft_strcmp(t->set, "m") == 0 || ft_strcmp(t->set, "j") == 0)
		iter_loop_mandelbrot(t);
}
