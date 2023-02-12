/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 04:03:19 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/12 02:16:06 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	write(1, "\033[31m", 5);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	write(1, "\033[0m", 5);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	exit_handler(void)
{
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_stru *fract)
{
	(void)fract;
	if (keycode == 53)
		exit_handler();
	return (1);
}
