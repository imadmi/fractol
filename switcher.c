/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:12:27 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/03 18:24:02 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	switcher(int keycode, t_fract *t)
{
	if (keycode == 46)
	{
		init_env(t, "m");
		draw_set(t);
	}
	if (keycode == 38)
	{
		init_env(t, "j");
		draw_set(t);
	}
}
