/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:12:39 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/08 04:03:16 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 1500
# define HIGHT 1500

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
	double			x_zero;
	double			y_zero;
	double			xtmp;
	double			ytmp;
	double			zoom_coff;
	int				iter;
	int				size_l;
	int				bpp;
	int				endian;
	int				index;
	int				zoom;
	int				stop;
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
void	init_var(t_stru *t, char *str);
void	choose_set(t_stru *t);
void	iter_loop_mandelbrot(t_stru *t);
void	set_color(t_stru *t, int color);
void	switcher(int keycode, t_stru *t);
void	map(t_stru *t);
void	zoom(t_stru *t, double x, double y, double zoom);
void	my_mlx_hook(t_stru *t);
void	map_julia(t_stru *t);
void	looping(t_stru *t);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		mouse_move(int x, int y, t_stru *t);
int		mouse_press(int btn, int x, int y, t_stru *t);
int		quiet(t_stru *t);
int		key_handler(int keycode, t_stru *t);
void	exit_handler(t_stru *t);

#endif
