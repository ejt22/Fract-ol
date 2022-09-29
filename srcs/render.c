/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:46:49 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/09/29 12:20:11 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* This function puts a pixel to an image. */

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* This function puts a pixel of the Mandelbrot fractal onto the image img. */

void	onepix_mb(t_fvars *fvars, t_img *img, t_data *data)
{
	int	iter;

	iter = 0;
	fvars->c_re = fvars->zoom * (fvars->x - WIDTH / 2.0) / (WIDTH / 4.0);
	fvars->c_im = fvars->zoom * (fvars->y - HEIGHT / 2.0) / (HEIGHT / 4.0);
	fvars->old_re = 0;
	fvars->old_im = 0;
	while (fvars->old_re * fvars->old_re + fvars->old_im * fvars->old_im <= 4
		&& iter < fvars->iter_max)
	{
		fvars->new_re = fvars->old_re * fvars->old_re
			- fvars->old_im * fvars->old_im + fvars->c_re;
		fvars->new_im = 2 * fvars->old_re * fvars->old_im + fvars->c_im;
		fvars->old_re = fvars->new_re;
		fvars->old_im = fvars->new_im;
		iter++;
	}
	if (iter < fvars->iter_max)
		my_mlx_pixel_put(img, fvars->x, fvars->y, encode_colour(iter, data));
	else
		my_mlx_pixel_put(img, fvars->x, fvars->y, create_trgb(1, 0, 0, 0));
}

/* This function puts a pixel of the Julia fractal onto the image img. */

void	onepix_jul(t_fvars *fvars, t_img *img, t_data *data)
{
	int	iter;

	iter = 0;
	fvars->old_re = fvars->zoom * (fvars->x - WIDTH / 2.0) / (WIDTH / 4.0);
	fvars->old_im = fvars->zoom * (fvars->y - HEIGHT / 2.0) / (HEIGHT / 4.0);
	while (fvars->old_re * fvars->old_re + fvars->old_im * fvars->old_im <= 4
		&& iter < fvars->iter_max)
	{
		fvars->new_re = fvars->old_re * fvars->old_re
			- fvars->old_im * fvars->old_im + fvars->c_re;
		fvars->new_im = 2 * fvars->old_re * fvars->old_im + fvars->c_im;
		fvars->old_re = fvars->new_re;
		fvars->old_im = fvars->new_im;
		iter++;
	}
	if (iter < fvars->iter_max)
		my_mlx_pixel_put(img, fvars->x, fvars->y, encode_colour(iter, data));
	else
		my_mlx_pixel_put(img, fvars->x, fvars->y, create_trgb(1, 0, 0, 0));
}

/* This function renders the correct fractal on the image created in data. */

void	render(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->fvars.x = x;
			data->fvars.y = y;
			if (data->type == 1)
				onepix_mb(&data->fvars, &data->img, data);
			else if (data->type == 2)
				onepix_jul(&data->fvars, &data->img, data);
			else
				break ;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
