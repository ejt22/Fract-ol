/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:19:45 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/09/29 11:59:47 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* This function displays error messages and exits the programme in case of
an error. */

void	error_msg(void)
{
	ft_putendl_fd("Invalid arguments", 2);
	ft_putendl_fd("The correct format is:", 2);
	ft_putendl_fd("./Fractol Mandelbrot <colour set 1, 2, or 3>", 2);
	ft_putstr_fd("or ./Fractol Julia <cReal> <cImaginary>", 2);
	ft_putstr_fd(" <colour set 1, 2, or 3>\n", 2);
	ft_putendl_fd("cRe, cIm and colour set are optional.", 2);
	exit (EXIT_FAILURE);
}

/* This function checks appropriate allocation for mlx and exits 
if necessary. */

void	check_mlx(t_data *data)
{
	if (!data->mlx)
	{
		clean_data(data);
		perror("Mlx init error\n");
		exit(EXIT_FAILURE);
	}
}

/* This function checks appropriate allocation for a window and exits 
if necessary. */

void	check_win(t_data *data)
{
	if (!data->win)
	{
		clean_data(data);
		free(data->mlx);
		perror("Window error!\n");
		exit(EXIT_FAILURE);
	}
}

/* This function checks appropriate allocation for an image and exits 
if necessary. */

void	check_img(t_data *data)
{
	if (!data->img.img || !data->img.addr)
	{
		mlx_destroy_window(data->mlx, data->win);
		clean_data(data);
		free(data->mlx);
		perror("Image error!\n");
		exit(EXIT_FAILURE);
	}
}
