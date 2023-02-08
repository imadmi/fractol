/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:07:24 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/08 04:03:37 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter_loop_mandelbrot(t_stru *fract)
{
	while (fract->iter < fract->max)
	{
		fract->xtmp = fract->x * fract->x - fract->y * fract->y;
		fract->ytmp = 2 * fract->x * fract->y;
		fract->x = fract->xtmp + fract->x_zero;
		fract->y = fract->ytmp + fract->y_zero;
		if (fract->x * fract->x + fract->y * fract->y > 4)
			break ;
		fract->iter++;
	}
}

void	looping(t_stru *fract)
{
	if (ft_strcmp(fract->set, "m") == 0 || ft_strcmp(fract->set, "j") == 0)
		iter_loop_mandelbrot(fract);
}
