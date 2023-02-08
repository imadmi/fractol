/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:52:46 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/08 04:03:13 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_stru *fract)
{
	fract->y_real = 0;
	while (fract->y_real < WIDTH)
	{
		fract->x_real = 0;
		while (fract->x_real < HIGHT)
		{
			fract->iter = 0;
			map_julia(fract);
			looping(fract);
			if (fract->iter == fract->max)
				set_color(fract, 0);
			else
				set_color(fract, 1);
			fract->x_real++;
		}
		fract->y_real++;
	}
	my_mlx_hook(fract);
}

void	mandelbrot(t_stru *fract)
{
	fract->y_real = 0;
	while (fract->y_real < HIGHT)
	{
		fract->x_real = 0;
		while (fract->x_real < WIDTH)
		{
			fract->iter = 0;
			map(fract);
			looping(fract);
			if (fract->iter == fract->max)
				set_color(fract, 0);
			else
				set_color(fract, 1);
			fract->x_real++;
		}
		fract->y_real++;
	}
	fract->stop = 1;
	my_mlx_hook(fract);
}
