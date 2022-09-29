/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:38:33 by elsajoo-tho       #+#    #+#             */
/*   Updated: 2022/09/29 11:59:50 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* This function codes for key hooks: ESC to exit the programme, as well as 
+ and - to zoom in and out. */

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		clean_exit(data);
	else if (keycode == 78)
		data->fvars.zoom *= 1.2;
	else if (keycode == 69)
		data->fvars.zoom *= 0.8;
	render(data);
	return (0);
}

/* This function codes for mouse hooks: mouse wheel to zoom in and out. */

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode == 4)
		data->fvars.zoom *= 0.8;
	else if (keycode == 5)
		data->fvars.zoom *= 1.2;
	(void) x;
	(void) y;
	render(data);
	return (0);
}
