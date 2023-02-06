/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:27:04 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/03 18:24:02 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, t_fract *t)
{
	if (x >= 0 && y >= 0 && x < WIDTH && y < WIDTH && t->stop == 0
		&& ft_strcmp(t->set, "j") == 0)
	{
		t->x_zero = (((double)x / WIDTH) * 4) - 2;
		t->y_zero = (((double)y / HIGHT) * 4) - 2;
		draw_set(t);
	}
	return (1);
}

int	mouse_press(int btn, int x, int y, t_fract *t)
{
	if (btn == 5 && t->stop == 1)
	{
		zoom(t, (double)x, (double)y, 1.1);
		t->zoom_coff *= 1.101;
	}
	else if (btn == 4 && t->stop == 1)
	{
		zoom(t, (double)x, (double)y, 0.9);
		t->zoom_coff /= 1.101;
	}
	draw_set(t);
	return (1);
}

void	zoom(t_fract *t, double x, double y, double zoom)
{
	double	x_map;
	double	y_map;

	x = WIDTH / 2;
	y = HIGHT / 2;
	x_map = ((x / WIDTH) * (t->end_x - t->start_x)) + t->start_x;
	y_map = ((y / HIGHT) * (t->end_y - t->start_y)) + t->start_y;
	t->start_x = x_map + ((t->start_x - x_map) * zoom);
	t->start_y = y_map + ((t->start_y - y_map) * zoom);
	t->end_y = y_map + ((t->end_y - y_map) * zoom);
	t->end_x = x_map + ((t->end_x - x_map) * zoom);
	if (t->max <= 120)
		t->max += 2;
}

int	quiet(t_fract *t)
{
	exit_handler(t);
	return (0);
}
