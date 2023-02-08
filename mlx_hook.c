/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:42:19 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/08 04:03:58 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_hook(t_stru *fract)
{
	mlx_put_image_to_window(fract->ptr, fract->win, fract->image, 0, 0);
	mlx_hook(fract->win, 4, 0, mouse_press, fract);
	mlx_hook(fract->win, 6, 0, mouse_move, fract);
	mlx_hook(fract->win, 2, 0, key_handler, fract);
	mlx_hook(fract->win, 17, 0, quiet, fract);
	mlx_loop(fract->ptr);
}
