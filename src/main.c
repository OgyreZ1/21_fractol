/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:14:40 by yironmak          #+#    #+#             */
/*   Updated: 2022/02/26 19:15:41 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_e(t_env *e)
{
	e->mlx = mlx_init();
	e->height = 500;
	e->width = 500;
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Fractol");
	e->img.img_ptr = mlx_new_image(e->mlx, e->width, e->height);
	e->img.addr = mlx_get_data_addr(e->img.img_ptr, &(e->img.bits_per_pixel), \
									&(e->img.size_line), &(e->img.endian));
}

int	main(int argc, char **argv)
{
	t_env	e;

	(void)argc;
	(void)argv;
	init_e(&e);
	mlx_mouse_hook(e.win, deal_mouse, &e);
	mlx_key_hook(e.win, deal_key, &e);
	mandelbrot(&e);
	mlx_loop(e.mlx);
}
