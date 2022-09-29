/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:47:52 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/09/29 11:59:49 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* This function initialises the data structure. */

static int	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->type = 0;
	data->colour = 1;
	data->img.img = NULL;
	data->img.addr = NULL;
	data->img.bits_per_pixel = 0;
	data->img.line_length = 0;
	data->img.endian = 0;
	data->fvars.x = 0;
	data->fvars.y = 0;
	data->fvars.c_re = 0.3;
	data->fvars.c_im = 0.5;
	data->fvars.old_re = 0;
	data->fvars.new_re = 0;
	data->fvars.old_im = 0;
	data->fvars.new_im = 0;
	data->fvars.zoom = 1;
	data->fvars.iter_max = 100;
	return (0);
}

/* This function initialises minilibx, the window and the image necessary
to draw the project. */

static void	init_graph(t_data *data)
{
	data->mlx = mlx_init();
	check_mlx(data);
	if (data->type == 1)
		data->win = mlx_new_window(data->mlx, HEIGHT, WIDTH, "Mandelbrot");
	else if (data->type == 2)
		data->win = mlx_new_window(data->mlx, HEIGHT, WIDTH, "Julia");
	check_win(data);
	data->img.img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	check_img(data);
}

/* This function cleans up the data struture. */

int	clean_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->type = 0;
	data->colour = 0;
	data->img.img = NULL;
	data->img.addr = NULL;
	data->img.bits_per_pixel = 0;
	data->img.line_length = 0;
	data->img.endian = 0;
	data->fvars.x = 0;
	data->fvars.y = 0;
	data->fvars.c_re = 0;
	data->fvars.c_im = 0;
	data->fvars.old_re = 0;
	data->fvars.new_re = 0;
	data->fvars.old_im = 0;
	data->fvars.new_im = 0;
	data->fvars.zoom = 0;
	data->fvars.iter_max = 0;
	return (0);
}

/* This function destroys all that needs to be destroyed, cleans the data
structure and exits the programme upon success. */

int	clean_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	clean_data(data);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	init_data(&data);
	check_input(argc, argv, &data);
	init_graph(&data);
	render(&data);
	mlx_hook(data.win, 17, 1L << 17, &clean_exit, &data);
	mlx_key_hook(data.win, &key_hook, &data);
	mlx_mouse_hook(data.win, &mouse_hook, &data);
	mlx_loop(data.mlx);
	free(data.mlx);
	return (0);
}
