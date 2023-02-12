/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:21:10 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/12 06:30:03 by imimouni         ###   ########.fr       */
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
		mandelbrot(fract);
		mlx_put_image_to_window(fract->ptr, fract->win, fract->image, 0, 0);
		mlx_loop(fract->ptr);
	}
	else
		ft_putstr("Try: ./fractol <set name : m or j>\n");
}

void	init_var(t_stru *fract, char *str)
{
	if (!ft_strcmp(str, "j"))
	{
		fract->start_x = -2;
		fract->end_x = 2;
		fract->start_y = -2;
		fract->end_y = 2;
	}
	if (!ft_strcmp(str, "m"))
	{
		fract->start_x = -2;
		fract->end_x = 1;
		fract->start_y = -1.5;
		fract->end_y = 1.5;
	}
	fract->c_real = -0.8;
	fract->c_imag = 0.156;
	fract->zoom = 1.2;
	fract->max = 50;
	fract->color = 20;
}

int	valid_args(char *av)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if ((av[0] == '-' || av[0] == '+') && av[1] != '\0')
		i++;
	while (av[i])
	{
		if (av[i] == '.')
		{
			i++;
			count++;
		}
		if ((!(av[i] >= '0' && av[i] <= '9')) || count == 2)
			return (0);
		i++;
	}
	return (1);
}

void	start(t_stru *fract, char *str)
{
	fract->ptr = mlx_init();
	fract->win = mlx_new_window(fract->ptr, WIDTH, HIGHT, "Fractol");
	fract->image = mlx_new_image(fract->ptr, WIDTH, HIGHT);
	fract->chr = (char *)mlx_get_data_addr(fract->image, &fract->bpp,
			&fract->line_bytes, &fract->endian);
	init_var(fract, str);
	fract->set = str;
	choose_set(fract);
}

int	main(int ac, char **av)
{
	t_stru		fract;

	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "m") || !ft_strcmp(av[1], "j"))
			start(&fract, av[1]);
		ft_putstr("Try: ./fractol <set name : m or j>\n");
		exit(0);
	}
	else if (ac == 4)
	{
		if (!ft_strcmp(av[1], "j") && valid_args(av[2]) && valid_args(av[3]))
		{
			start(&fract, av[1]);
			fract.c_real = ft_atof(av[2]);
			fract.c_imag = ft_atof(av[3]);
			choose_set(&fract);
		}
		ft_putstr("Try: ./fractol <set name : m or j>\n");
		exit(0);
	}
	else
		ft_putstr("Try: ./fractol <set name : m or j>\n");
	return (0);
}
