/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:13:03 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/09/29 12:13:50 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* This function parses the arguments of the main for the Mandelbrot type. */

static void	parse_mb(int argc, char *argv[], t_data *data)
{
	data->type = 1;
	if (argc == 3)
	{
		data->colour = ft_atoi(argv[2]);
		if (data->colour > 3 || data->colour == 0)
			error_msg();
	}
	if (argc > 3)
		error_msg();
}

/* This function parses the arguments of the main for the Julia type. */

static void	parse_jul(int argc, char *argv[], t_data *data)
{
	data->type = 2;
	if (argc == 3)
	{
		if (!ft_strncmp(ft_strlowcase(argv[2]), "1", 2)
			|| !ft_strncmp(ft_strlowcase(argv[2]), "2", 2)
			|| !ft_strncmp(ft_strlowcase(argv[2]), "3", 2))
		{
			data->colour = ft_atoi(argv[2]);
			if (data->colour > 3 || data->colour == 0)
				error_msg();
		}	
		else
			error_msg();
	}
	if (argc == 4)
	{
		data->fvars.c_re = ft_atof(argv[2]);
		data->fvars.c_im = ft_atof(argv[3]);
	}
	if (argc == 5)
	{
		data->fvars.c_re = ft_atof(argv[2]);
		data->fvars.c_im = ft_atof(argv[3]);
		data->colour = ft_atoi(argv[4]);
	}		
}

/* This function parses the arguments of the main and deals with 
potential errors. */

void	check_input(int argc, char *argv[], t_data *data)
{
	if (argc < 2 || argc > 5)
		error_msg();
	else if (!ft_strncmp(ft_strlowcase(argv[1]), "mandelbrot", 11))
		parse_mb(argc, argv, data);
	else if (!ft_strncmp(ft_strlowcase(argv[1]), "julia", 6))
		parse_jul(argc, argv, data);
	else
		error_msg();
}
