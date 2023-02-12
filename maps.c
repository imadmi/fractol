/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:14:48 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/12 02:37:13 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	map_mandelbrot(t_stru *fract)
{
	fract->x = fract->x_real * ((fract->end_x - fract->start_x) / WIDTH)
		+ fract->start_x;
	fract->y = fract->y_real * ((fract->end_y - fract->start_y) / HIGHT)
		+ fract->start_y;
	fract->c_real = fract->x;
	fract->c_imag = fract->y;
}

void	map_julia(t_stru *fract)
{
	fract->x = fract->x_real * ((fract->end_x - fract->start_x) / WIDTH)
		+ fract->start_x;
	fract->y = fract->y_real * ((fract->end_y - fract->start_y) / HIGHT)
		+ fract->start_y;
}

void	set_color(t_stru *fract)
{
	fract->index = (fract->line_bytes * fract->y_real) + fract->x_real * 4;
	fract->chr[fract->index] = (fract->iter * fract->color);
	fract->chr[fract->index + 1] = (fract->iter * fract->color * 0.5);
	fract->chr[fract->index + 2] = (fract->iter * fract->color * 14);
	fract->chr[fract->index + 3] = 0;
}

void	looping(t_stru *fract)
{
	while (fract->iter < fract->max)
	{
		fract->xtemp = fract->x * fract->x - fract->y * fract->y;
		fract->ytemp = 2 * fract->x * fract->y;
		fract->x = fract->xtemp + fract->c_real;
		fract->y = fract->ytemp + fract->c_imag;
		if (fract->x * fract->x + fract->y * fract->y > 4)
			break ;
		fract->iter++;
	}
}
