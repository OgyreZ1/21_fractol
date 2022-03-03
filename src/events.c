/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:07:30 by yironmak          #+#    #+#             */
/*   Updated: 2022/03/03 15:21:41 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int x, int y, t_env *e)
{
	double	old_zoom;

	old_zoom = e->zoom_k;
	e->zoom_k = e->zoom_const / e->zoom;
	e->x += (old_zoom - e->zoom_k) / 2;
	e->y += (old_zoom - e->zoom_k) / 2;
	x = x - e->width / 2;
	y = y - e->height / 2;
	e->x += (x * old_zoom / e->width) - (x * e->zoom_k / e->width);
	e->y += (y * old_zoom / e->height) - (y * e->zoom_k / e->height);
	e->x_zoom = e->width / e->zoom_k;
	e->y_zoom = e->height / e->zoom_k;
	draw_set(e);
}

int	deal_mouse(int button, int x, int y, t_env *e)
{
	if (button == 1 || button == 5)
	{
		e->zoom *= 1.1;
		if (e->max < 250)
			e->max++;
	}
	else if (button == 2 || button == 4)
	{
		e->zoom /= 1.1;
		if (e->max > 50)
			e->max--;
	}
	zoom(x, y, e);
	return (0);
}

void	change_set(int key, t_env *e)
{
	if (key == 18)
		init_mandelbrot(e);
	else if (key == 19)
		init_julia_1(e);
	else if (key == 20)
		init_julia_2(e);
	else if (key == 21)
		init_julia_3(e);
	else if (key == 23)
		init_burning_ship(e);
}

int	deal_key(int key, t_env *e)
{
	if (key == 2)
		e->x += 0.1 / e->zoom;
	else if (key == 0)
		e->x -= 0.1 / e->zoom;
	else if (key == 1)
		e->y += 0.1 / e->zoom;
	else if (key == 13)
		e->y -= 0.1 / e->zoom;
	else if (key >= 82 && key <= 92)
		e->color_scheme = key - 82;
	change_set(key, e);
	draw_set(e);
	if (key == 53)
	{
		mlx_destroy_image(e->mlx, e->img.img_ptr);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	return (0);
}
