/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:52:46 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/03 18:24:02 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fract *t)
{
	t->y_real = 0;
	while (t->y_real < WIDTH)
	{
		t->x_real = 0;
		while (t->x_real < HIGHT)
		{
			t->iter = 0;
			map_julia(t);
			looping(t);
			if (t->iter == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_real++;
		}
		t->y_real++;
	}
	my_mlx_hook(t);
}

void	mandelbrot(t_fract *t)
{
	t->y_real = 0;
	while (t->y_real < HIGHT)
	{
		t->x_real = 0;
		while (t->x_real < WIDTH)
		{
			t->iter = 0;
			map(t);
			looping(t);
			if (t->iter == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_real++;
		}
		t->y_real++;
	}
	t->stop = 1;
	my_mlx_hook(t);
}
