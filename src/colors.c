/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:05:25 by yironmak          #+#    #+#             */
/*   Updated: 2022/02/27 19:39:40 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_scheme(int n, t_env *e)
{
	int	colors[16];

	colors[0] = 0x1a0707;
	colors[1] = 0x19071A;
	colors[2] = 0x07191a;
	colors[3] = 0xF8C95F;
	colors[4] = 0xD3ECF8;
	colors[5] = 0xAAAAAA;
	colors[6] = 0x1852B1;
	colors[7] = 0x071a0b;
	colors[8] = 0x181a07;
	colors[9] = 0x181a07;
	colors[10] = 0xF1E9BF;
	return (colors[e->color_scheme] * (n % 16));
}

void	pixel_put_img(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	choose_color(t_env *e)
{
	if (e->i < e->max)
		pixel_put_img(&e->img, e->xi, e->yi, color_scheme(e->i, e));
	else
		pixel_put_img(&e->img, e->xi, e->yi, 0x0);
}
