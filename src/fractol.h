/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:00:04 by yironmak          #+#    #+#             */
/*   Updated: 2022/02/27 19:49:43 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "stdio.h"
# include <unistd.h>
# include "stdlib.h"

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_image;

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_env
{
	int			height;
	int			width;
	void		*mlx;
	void		*win;
	double		zoom_const;
	double		zoom_k;
	double		x;
	double		y;
	double		x_zoom;
	double		y_zoom;
	int			xi;
	int			yi;
	t_complex	z;
	t_complex	c;
	double		temp;
	t_image		img;
	double		zoom;
	int			max;
	int			i;
	int			set;
	int			color_scheme;
}				t_env;

int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_strlen(const char *s);
void	ft_putstr(char *s);
int		color_scheme(int n, t_env *e);
void	pixel_put_img(t_image *img, int x, int y, int color);
void	choose_color(t_env *e);
int		deal_mouse(int button, int x, int y, t_env *e);
int		deal_key(int key, t_env *e);
void	draw_set(t_env *e);
void	init_mandelbrot(t_env *e);
void	init_julia_1(t_env *e);
void	init_julia_2(t_env *e);
void	init_julia_3(t_env *e);
void	init_burning_ship(t_env *e);
void	mandelbrot(t_env *e);
void	julia(t_env *e);
void	burning_ship(t_env *e);

#endif