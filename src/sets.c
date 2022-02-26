/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:21:59 by yironmak          #+#    #+#             */
/*   Updated: 2022/02/26 19:15:44 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_env *e)
{
	e->x = -2;
	e->y = -1.35;
	e->zoom_const = 2.8;
	e->zoom_k = 2.8;
	e->zoom = 1;
	e->max = 50;
	e->x_zoom = e->width / e->zoom_k;
	e->y_zoom = e->height / e->zoom_k;
}

void	mandelbrot(t_env *e)
{
	e->yi = 0;
	while (e->yi < e->height)
	{
		e->xi = 0;
		while (e->xi < e->width)
		{
			e->c.re = e->xi / e->x_zoom + e->x;
			e->c.im = e->yi / e->y_zoom + e->y;
			e->z.re = 0;
			e->z.im = 0;
			e->i = 0;
			while (e->i < e->max && e->z.re * e->z.re + e->z.im * e->z.im <= 4)
			{
				e->temp = e->z.re * e->z.re - e->z.im * e->z.im + e->c.re;
				e->z.im = 2.0 * e->z.re * e->z.im + e->c.im;
				e->z.re = e->temp;
				e->i++;
			}
			choose_color(e);
			e->xi++;
		}
		e->yi++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
}
