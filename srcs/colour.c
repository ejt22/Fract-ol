/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:12:55 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/09/29 11:59:48 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* This function takes the RGB values ranging 0-255 and puts them into TRGB 
hexadecimal format. */

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/* This function calculates for colour set 1 the colour of each pixel
depending on its 'iter'. The background is in shades of blue and then
a 'rainbow effect'.*/

static int	colour_1(int iter, t_fvars *fvars)
{
	(void) fvars;
	if (iter <= 20)
		return (create_trgb(1, 45, 150 - iter * 150 / 20, 255));
	else if (iter > 20 && iter % 6 == 4)
		return (create_trgb(1, 220, 0, 220));
	else if (iter > 20 && iter % 6 == 5)
		return (create_trgb(1, 255, 150, 0));
	else if (iter > 20 && iter % 6 == 0)
		return (create_trgb(1, 70, 70, 70));
	else if (iter > 20 && iter % 6 == 1)
		return (create_trgb(1, 175, 255, 0));
	else if (iter > 20 && iter % 6 == 2)
		return (create_trgb(1, 0, 0, 255));
	else
		return (create_trgb(1, 0, 0, 255));
}

/* This function calculates for colour set 2 the colour of each pixel
depending on its 'iter'. The background is in shades of blue and then
a colour gradient to pink colours. */

static int	colour_2(int iter, t_fvars *fvars)
{
	int	d;

	if (iter <= 20)
		return (create_trgb(1, 45, 150 - iter * 150 / 20, 255));
	else if (iter > 20 && iter <= fvars->iter_max / 4)
	{
		d = iter - 20;
		return (create_trgb(1,
				45 + (d * (220 - 45) / (fvars->iter_max / 4 - 20)),
				0, 255 + (d * (220 - 245) / (fvars->iter_max / 4 - 20))));
	}
	else if (iter > fvars->iter_max / 4 && iter < fvars->iter_max)
	{
		d = iter - fvars->iter_max / 4;
		return (create_trgb(1, 220, 0,
				220 - (d * 220 / (3 * fvars->iter_max / 4))));
	}
	else
		return (create_trgb(1, 255, 255, 255));
}

/* This function calculates for colour set 3 the colour of each pixel
depending on its 'iter'. The background is in shades of green to blue 
and then a colour gradient to yellow colours. */

static int	colour_3(int iter, t_fvars *fvars)
{
	int	d;

	if (iter <= 20)
		return (create_trgb(1, 7, 235 - iter * 235 / 20, 120));
	else if (iter > 20 && iter <= fvars->iter_max / 4)
	{
		d = iter - 20;
		return (create_trgb(1, 7 + (d * (190 - 7) / (fvars->iter_max / 4 - 15)),
				d * 255 / (fvars->iter_max / 4 - 15),
				120 + (d * (20 - 120) / (fvars->iter_max / 4 - 15))));
	}
	else if (iter > fvars->iter_max / 4 && iter < fvars->iter_max)
	{
		d = iter - fvars->iter_max / 4;
		return (create_trgb(1,
				190 + (d * (255 - 190) / (3 * fvars->iter_max / 4)),
				255, 120 - (d * 120 / (3 * fvars->iter_max / 4))));
	}
	else
		return (create_trgb(1, 255, 255, 255));
}

/* This function encodes the colour of each pixel depending on the colour
set given as a parameter in data. */

int	encode_colour(int iter, t_data *data)
{
	if (data->colour == 2)
		return (colour_2(iter, &data->fvars));
	else if (data->colour == 3)
		return (colour_3(iter, &data->fvars));
	else
		return (colour_1(iter, &data->fvars));
}
