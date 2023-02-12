/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:21:10 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/12 01:08:35 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_set(t_stru *fract)
{
	if (!ft_strcmp(fract->set, "j"))
	{
		julia(fract);
		mlx_put_image_to_window(fract->ptr, fract->win, fract->image, 0, 0);
		mlx_loop(fract->ptr);
	}
	else if (!ft_strcmp(fract->set, "m"))
	{
		// fract->start_x = -2;
		// fract->end_x = 1;
		// fract->start_y = -1.5;
		// fract->end_y = 1.5;
		mandelbrot(fract);
		mlx_put_image_to_window(fract->ptr, fract->win, fract->image, 0, 0);
		mlx_loop(fract->ptr);
	}
	else
		ft_putstr("Try: ./fractol <set name : m or j>\n");
}

void	init_var(t_stru *fract, char *str)
{
	if(!ft_strcmp(str, "j"))
	{
		fract->start_x = -2;
		fract->end_x = 2;
		fract->start_y = -2;
		fract->end_y = 2;
	}
	if(!ft_strcmp(str, "m"))
	{
		fract->start_x = -2;
		fract->end_x = 1;
		fract->start_y = -1.5;
		fract->end_y = 1.5;
	}
	fract->c_real = -0.8;
	fract->c_imag = 0.156;
	fract->zoom = 1.2; // massal7 l walo 
	fract->max = 50;
	fract->color = 20;
}

int	main(int ac, char **av)
{
	t_stru		fract;

	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "m") || !ft_strcmp(av[1], "j"))
		{
			fract.ptr = mlx_init(); //return a void * which holds the location of our current MLX instance
			fract.win = mlx_new_window(fract.ptr, WIDTH, HIGHT, "Fractol"); //Return a pointer to the window we have just created
			fract.image = mlx_new_image(fract.ptr, WIDTH, HIGHT);
			fract.chr = (char *)mlx_get_data_addr(fract.image, &fract.bpp,
					&fract.line_bytes, &fract.endian); // returns a char * address that represents the begining of the memory area where the image is stored
			init_var(&fract , av[1]); // itisialize our variables 
		}
		fract.set = av[1];
		choose_set(&fract);
	}
	else
		ft_putstr("Try: ./fractol <set name : m or j>\n");
	return (0);
}
