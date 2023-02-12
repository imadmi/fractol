/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:12:39 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/12 01:07:57 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WIDTH 400
# define HIGHT 400
// # define WIDTH 1400
// # define HIGHT 1400

typedef struct s_struc
{
	double			x;
	double			y;
	double			x_real;
	double			y_real;
	double			start_x;
	double			start_y;
	double			end_x;
	double			end_y;
	double			c_real;
	double			c_imag;
	double			xtemp;
	double			ytemp;
	double			zoom;
	int				iter;
	int				line_bytes;
	int				bpp;
	int				endian;
	int				index;
	int				color;
	int				max;
	void			*ptr;
	void			*win;
	void			*image;
	char			*set;
	char			*chr;

}					t_stru;

void	mandelbrot(t_stru *t);
void	julia(t_stru *t);
void	init_var(t_stru *t, char * str);
void	choose_set(t_stru *fract);
void	set_color(t_stru *t);
void	map_mandelbrot(t_stru *t);
void	map_julia(t_stru *t);
void	mlx__hook(t_stru *t);
void	looping(t_stru *t);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		mouse_move(int x, int y, t_stru *t);
int		key_handler(int keycode, t_stru *t);
int		exit_handler();

#endif
