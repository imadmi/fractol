/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:21:10 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/04 13:46:17 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage_message(void)
{
	ft_putstr("\tTry: ./fractol <set a name> | m j\nfeatures :\n");
	ft_putstr(
		" \t m and j buttons to switch from a set to another \n");
	ft_putstr(" \t arrows to navigate through the set\n");
	ft_putstr(" \t mouse while to zoom in and out\n");
	ft_putstr(" \t + and - to add or substract max iteration\n");
	ft_putstr(" \t i to return to the initial form of set\n");
	ft_putstr(" \t space button to stop Julia set\n");
}

void	draw_set(t_fract *t)
{
	if (ft_strcmp(t->set, "j") == 0)
		julia(t);
	else if (ft_strcmp(t->set, "m") == 0)
		mandelbrot(t);
	else
		ft_putstr(
			"\tTry: ./fractol <set a name> | m  j\n");
}

void	init_env(t_fract *t, char *str)
{
	t->zoom_coff = 0.040;
	t->start_x = -2;
	t->end_x = 2;
	t->start_y = -2;
	t->end_y = 2;
	t->x_zero = -0.4;
	t->y_zero = 0.6;
	t->zoom = 0;
	t->stop = 0;
	t->max = 40;
	t->color = 6;
	t->set = str;
}

int	main(int ac, char **av)
{
	t_fract		fract;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "m") == 0
			|| ft_strcmp(av[1], "j") == 0)
		{
			fract.ptr = mlx_init();
			fract.win = mlx_new_window(fract.ptr, WIDTH, HIGHT, "Fractol");
			fract.image = mlx_new_image(fract.ptr, WIDTH, HIGHT);
			fract.chr = (unsigned char *)mlx_get_data_addr(fract.image, &fract.bpp,
					&fract.size_l, &fract.endian);
		}
		init_env(&fract, av[1]);
		draw_set(&fract);
	}
	else
		usage_message();
	return (0);
}
