/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:22:23 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/09/22 13:37:05 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 1000
# define WIDTH 1000

typedef struct s_fvars
{
	int		x;
	int		y;
	double	c_re;
	double	c_im;
	double	old_re;
	double	new_re;
	double	old_im;
	double	new_im;
	double	zoom;
	double	iter_max;
}	t_fvars;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		type;
	int		colour;
	t_img	img;
	t_fvars	fvars;
}	t_data;

// lifbt utils

void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strlowcase(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// parsing utils

double	ft_atof(char *s);
int		ft_atoi(const char *str);

// parsing

void	check_input(int argc, char *argv[], t_data *data);

// error
void	error_msg(void);
void	check_mlx(t_data *data);
void	check_win(t_data *data);
void	check_img(t_data *data);

// render

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	onepix_mb(t_fvars *fvars, t_img *img, t_data *data);
void	onepix_jul(t_fvars *fvars, t_img *img, t_data *data);
void	render(t_data *data);

// colour

int		create_trgb(int t, int r, int g, int b);
int		encode_colour(int iter, t_data *data);

// hooks

int		key_hook(int keycode, t_data *data);
int		mouse_hook(int keycode, int x, int y, t_data *data);

// fractol

int		clean_data(t_data *data);
int		clean_exit(t_data *data);

#endif
