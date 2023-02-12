/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:52:46 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/11 23:49:21 by imimouni         ###   ########.fr       */
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
			{
				fract->iter = 0;
				set_color(fract);
			}
			else
				set_color(fract);
			fract->x_real++;
		}
		fract->y_real++;
	}
	mlx__hook(fract);
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
			map_mandelbrot(fract);
			looping(fract);
			if (fract->iter == fract->max)
			{
				fract->iter = 0;
				set_color(fract);
			}
			else
				set_color(fract);
			fract->x_real++;
		}
		fract->y_real++;
	}
	mlx__hook(fract);
}
