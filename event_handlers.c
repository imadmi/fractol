/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:27:04 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/12 02:13:42 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, t_stru *fract)
{
	if (x >= 0 && y >= 0 && x < WIDTH && y < HIGHT
		&& !ft_strcmp(fract->set, "j"))
	{
		fract->c_real = (double)x / WIDTH;
		fract->c_imag = (double)y / HIGHT;
		choose_set(fract);
	}
	return (1);
}

void	zoom_out(t_stru *fract)
{
	fract->start_x *= fract->zoom;
	fract->start_y *= fract->zoom;
	fract->end_y *= fract->zoom;
	fract->end_x *= fract->zoom;
	fract->max -= 4;
	choose_set(fract);
}

void	zoom_in(t_stru *fract)
{
	fract->start_x /= fract->zoom;
	fract->start_y /= fract->zoom;
	fract->end_y /= fract->zoom;
	fract->end_x /= fract->zoom;
	fract->max += 4;
	choose_set(fract);
}

int	mouse_hook(int button, int x, int y, t_stru *fract)
{
	(void)x;
	(void)y;
	if (button == 5)
		zoom_out(fract);
	else if (button == 4)
		zoom_in(fract);
	return (0);
}

void	mlx__hook(t_stru *fract)
{
	mlx_hook(fract->win, 6, 0, mouse_move, fract);
	mlx_hook(fract->win, 2, 0, key_handler, fract);
	mlx_hook(fract->win, 17, 0, exit_handler, 0);
	mlx_mouse_hook(fract->win, mouse_hook, fract);
}
