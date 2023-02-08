/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:21:10 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/08 04:03:47 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_set(t_stru *fract)
{
	if (ft_strcmp(fract->set, "j") == 0)
		julia(fract);
	else if (ft_strcmp(fract->set, "m") == 0)
		mandelbrot(fract);
	else
		ft_putstr("Try: ./fractol <set name> | m  j\n");
}

#include <stdio.h>
void	init_var(t_stru *fract, char *str)
{
	fract->zoom_coff = 0.150;
	fract->start_x = -2;
	fract->end_x = 2;
	fract->start_y = -2;
	fract->end_y = 2;
	fract->x_zero = -0.4;
	fract->y_zero = 0.6;
	// fract->zoom = 2; // massal7 l walo 
	fract->stop = 0;
	fract->max = 50;
	fract->color = 20;
	fract->set = str;
}

int	main(int ac, char **av)
{
	t_stru		fract;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "m") == 0
			|| ft_strcmp(av[1], "j") == 0)
		{
			fract.ptr = mlx_init(); //return a void * which holds the location of our current MLX instance
			fract.win = mlx_new_window(fract.ptr, WIDTH, HIGHT, "Fractol"); //Return a pointer to the window we have just created
			fract.image = mlx_new_image(fract.ptr, WIDTH, HIGHT);
			fract.chr = (char *)mlx_get_data_addr(fract.image, &fract.bpp,
					&fract.size_l, &fract.endian); // returns a char * address that represents the begining of the memory area where the image is stored
		}
		init_var(&fract, av[1]); // itisialize our variables 
		choose_set(&fract);
	}
	else
		ft_putstr("Try: ./fractol <set name> | m j\n");
	return (0);
}
