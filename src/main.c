/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:14:40 by yironmak          #+#    #+#             */
/*   Updated: 2022/02/27 19:54:23 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_e(t_env *e)
{
	e->mlx = mlx_init();
	e->height = 500;
	e->width = 500;
	e->color_scheme = 0;
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Fractol");
	e->img.img_ptr = mlx_new_image(e->mlx, e->width, e->height);
	e->img.addr = mlx_get_data_addr(e->img.img_ptr, &(e->img.bits_per_pixel), \
									&(e->img.size_line), &(e->img.endian));
}

void	draw_set(t_env *e)
{
	if (e->set == 1)
		mandelbrot(e);
	if (e->set == 2)
		julia(e);
	if (e->set == 3)
		burning_ship(e);
}

void	print_params(void)
{
	ft_putstr("Choose one of them as an argument:\n");
	ft_putstr("1. Mandelbrot\n");
	ft_putstr("2. Julia_1\n");
	ft_putstr("3. Julia_2\n");
	ft_putstr("4. Julia_3\n");
	ft_putstr("5. Burning_ship\n");
	exit(1);
}

void	choose_set(char *arg, t_env *e)
{
	if (ft_strncmp(arg, "Mandelbrot", ft_strlen("Mandelbrot")) == 0)
		init_mandelbrot(e);
	else if (ft_strncmp(arg, "Julia_1", ft_strlen("Julia_1")) == 0)
		init_julia_1(e);
	else if (ft_strncmp(arg, "Julia_2", ft_strlen("Julia_2")) == 0)
		init_julia_2(e);
	else if (ft_strncmp(arg, "Julia_3", ft_strlen("Julia_3")) == 0)
		init_julia_3(e);
	else if (ft_strncmp(arg, "Burning_ship", ft_strlen("Burning_ship")) == 0)
		init_burning_ship(e);
	else
		print_params();
}

int	main(int argc, char **argv)
{
	t_env	e;

	if (argc == 1)
		print_params();
	init_e(&e);
	mlx_mouse_hook(e.win, deal_mouse, &e);
	mlx_key_hook(e.win, deal_key, &e);
	choose_set(argv[1], &e);
	mlx_loop(e.mlx);
}
