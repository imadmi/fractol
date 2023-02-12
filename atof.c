/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 05:46:35 by imimouni          #+#    #+#             */
/*   Updated: 2023/02/12 06:18:10 by imimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_parse_integer(char *str, int *i, int *sign)
{
	double	result;

	result = 0;
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

double	ft_parse_lfassila(char *str, int *i)
{
	double	lfassila;
	int		pos;

	lfassila = 0;
	pos = 1;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			lfassila = lfassila * 10 + (str[*i] - '0');
			pos *= 10;
			(*i)++;
		}
	}
	return (lfassila / pos);
}

double	ft_atof(char *str)
{
	double	result;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	result = ft_parse_integer(str, &i, &sign);
	result += ft_parse_lfassila(str, &i);
	return (sign * result);
}
