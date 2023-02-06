/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:14:48 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/03 18:24:02 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	map(t_fract *t)
{
	t->x = t->x_real / (WIDTH / (t->end_x - t->start_x)) + t->start_x;
	t->y = t->y_real / (HIGHT / (t->end_y - t->start_y)) + t->start_y;
	t->x_zero = t->x;
	t->y_zero = t->y;
}

void	set_color(t_fract *t, int color)
{
	t->index = (t->size_l * t->y_real) + t->x_real * 4;
	t->chr[t->index] = (t->iter * t->color + 20) * color;
	t->chr[t->index + 1] = (t->iter * t->color + 42) * color;
	t->chr[t->index + 2] = (t->iter * t->color + 93) * color;
	t->chr[t->index + 3] = 0;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	map_julia(t_fract *t)
{
	t->x = ((t->x_real / (double)WIDTH)
			* (t->end_x - t->start_x)) + t->start_x;
	t->y = ((t->y_real / (double)HIGHT)
			* (t->end_y - t->start_y)) + t->start_y;
}
