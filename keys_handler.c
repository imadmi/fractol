/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:21:15 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/08 04:03:44 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	arrow_handler(int keycode, t_stru *fract)
{
	if (keycode == 124)
	{
		fract->start_x = fract->start_x + fract->zoom_coff;
		fract->end_x = fract->end_x + fract->zoom_coff;
		choose_set(fract);
	}
	else if (keycode == 125)
	{
		fract->start_y = fract->start_y + fract->zoom_coff;
		fract->end_y = fract->end_y + fract->zoom_coff;
		choose_set(fract);
	}
	else if (keycode == 126)
	{
		fract->start_y = fract->start_y - fract->zoom_coff;
		fract->end_y = fract->end_y - fract->zoom_coff;
		choose_set(fract);
	}
	if (keycode == 123)
	{
		fract->start_x = fract->start_x - fract->zoom_coff;
		fract->end_x = fract->end_x - fract->zoom_coff;
		choose_set(fract);
	}
}

static void	iter_handler(int keycode, t_stru *fract)
{
	if (keycode == 69)
		fract->max += 8;
	if (keycode == 78)
		fract->max -= 8;
	choose_set(fract);
}

int	key_handler(int keycode, t_stru *fract)
{
	if (keycode >= 123 && keycode <= 126)
		arrow_handler(keycode, fract);
	if (keycode == 53)
		exit_handler(fract);
	if (keycode == 69 || keycode == 78)
		iter_handler(keycode, fract);
	if (keycode == 49 && ft_strcmp(fract->set, "j") == 0)
	{
		if (fract->stop)
			fract->stop = 0;
		else
			fract->stop = 1;
	}
	if (keycode == 11 || keycode == 46 || keycode == 38)
		switcher(keycode, fract);
	if (keycode == 34)
	{
		init_var(fract, fract->set);
		choose_set(fract);
	}
	return (1);
}



void	exit_handler(t_stru *fract)
{
	mlx_destroy_image(fract->ptr, fract->image);
	mlx_destroy_window(fract->ptr, fract->win);
	exit(0);
}
