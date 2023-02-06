/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:42:19 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/03 18:24:02 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_hook(t_fract *t)
{
	mlx_put_image_to_window(t->ptr, t->win, t->image, 0, 0);
	mlx_hook(t->win, 4, 0, mouse_press, t);
	mlx_hook(t->win, 6, 0, mouse_move, t);
	mlx_hook(t->win, 2, 0, key_handler, t);
	mlx_hook(t->win, 17, 0, quiet, t);
	mlx_loop(t->ptr);
}
