/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:14:48 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/08 04:03:55 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	map(t_stru *fract)
{
	fract->x = fract->x_real / (WIDTH / (fract->end_x - fract->start_x)) + fract->start_x;
	fract->y = fract->y_real / (HIGHT / (fract->end_y - fract->start_y)) + fract->start_y;
	fract->x_zero = fract->x;
	fract->y_zero = fract->y;
}

void	set_color(t_stru *fract, int color)
{
	// printf("<%d>",fract->iter);//
	fract->index = (fract->size_l * fract->y_real) + fract->x_real * 4;
	fract->chr[fract->index] = (fract->iter * fract->color + 20) * color;
	fract->chr[fract->index + 1] = (fract->iter * fract->color + 40) * color;
	fract->chr[fract->index + 2] = (fract->iter * fract->color + 100) * color;
	// fract->chr[fract->index + 3] = 0;
}

void	map_julia(t_stru *fract)
{
	fract->x = ((fract->x_real / (double)WIDTH)
			* (fract->end_x - fract->start_x)) + fract->start_x;
	fract->y = ((fract->y_real / (double)HIGHT)
			* (fract->end_y - fract->start_y)) + fract->start_y;
}
