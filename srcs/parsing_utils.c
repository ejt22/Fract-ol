/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:36:35 by elsajoo-tho       #+#    #+#             */
/*   Updated: 2022/09/29 12:04:06 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* This function takes a string as a parameter and outputs a double
but does not deal with the sign. */

static double	ft_atof2(char *s, int i)
{
	double	nb;
	int		dot;
	int		afterdot;

	nb = 0;
	dot = 0;
	afterdot = 0;
	while (s[i] && ((s[i] >= '0' && s[i] <= '9') || s[i] == '.'))
	{
		if (s[i] == '.' && dot == 1)
			break ;
		if (s[i] == '.' && dot == 0)
			dot = 1;
		if (s[i] != '.')
			nb = nb * 10.0 + (s[i] - '0');
		if ((s[i] >= '0' && s[i] <= '9') && dot == 1)
			afterdot++;
		i++;
	}
	while (afterdot > 0)
	{
		nb *= 0.1;
		afterdot--;
	}
	return (nb);
}

/* This function is like an atoi for doubles. */

double	ft_atof(char *s)
{
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	return (ft_atof2(s, i) * sign);
}

static int	protected_atoi(unsigned long long res, int sign, int size)
{
	unsigned long long	max;

	max = 9223372036854775807U;
	if (((res > max) || size > 19) && sign > 0)
		return (-1);
	else if (((res > (max + 1)) || size > 19) && sign < 0)
		return (0);
	return (res * sign);
}

/* This function takes a string as an argument and outputs an int. */

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	int					size;
	unsigned long long	res;

	i = 0;
	sign = 1;
	res = 0;
	size = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && ++size)
		res = res * 10 + (str[i++] - '0');
	return (protected_atoi(res, sign, size));
}
