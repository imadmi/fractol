/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:27:04 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/08 04:03:10 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, t_stru *fract)
{
	if (x >= 0 && y >= 0 && x < WIDTH && y < WIDTH && fract->stop == 0
		&& ft_strcmp(fract->set, "j") == 0)
	{
		fract->x_zero = (((double)x / WIDTH) * 4) - 2;
		fract->y_zero = (((double)y / HIGHT) * 4) - 2;
		choose_set(fract);
	}
	return (1);
}

int	mouse_press(int btn, int x, int y, t_stru *fract)
{
	if (btn == 5 && fract->stop == 1)
	{
		zoom(fract, (double)x, (double)y, 1.1);
		fract->zoom_coff *= 1.101;
	}
	else if (btn == 4 && fract->stop == 1)
	{
		zoom(fract, (double)x, (double)y, 0.9);
		fract->zoom_coff /= 1.101;
	}
	choose_set(fract);
	return (1);
}

void	zoom(t_stru *fract, double x, double y, double zoom)
{
	double	x_map;
	double	y_map;

	x = WIDTH / 2;
	y = HIGHT / 2;
	x_map = ((x / WIDTH) * (fract->end_x - fract->start_x)) + fract->start_x;
	y_map = ((y / HIGHT) * (fract->end_y - fract->start_y)) + fract->start_y;
	fract->start_x = x_map + ((fract->start_x - x_map) * zoom);
	fract->start_y = y_map + ((fract->start_y - y_map) * zoom);
	fract->end_y = y_map + ((fract->end_y - y_map) * zoom);
	fract->end_x = x_map + ((fract->end_x - x_map) * zoom);
	if (fract->max <= 120)
		fract->max += 2;
}

int	quiet(t_stru *fract)
{
	exit_handler(fract);
	return (0);
}
