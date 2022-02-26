/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:32:36 by yironmak          #+#    #+#             */
/*   Updated: 2022/02/26 20:00:13 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		if (s1[i] != s2[i] || s1[i] == 0 || s2[i] == 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		write(1, &(s[i]), 1);
}
