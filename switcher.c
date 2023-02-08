/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:12:27 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/08 04:04:01 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	switcher(int keycode, t_stru *fract)
{
	if (keycode == 46)
	{
		init_var(fract, "m");
		choose_set(fract);
	}
	if (keycode == 38)
	{
		init_var(fract, "j");
		choose_set(fract);
	}
}
