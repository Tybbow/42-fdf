/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:51:46 by tiskow            #+#    #+#             */
/*   Updated: 2018/02/19 20:15:05 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move(int keycode, t_ml *dna)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (keycode == UP)
		y -= 10;
	if (keycode == DOWN)
		y += 10;
	if (keycode == RIGHT)
		x += 10;
	if (keycode == LEFT)
		x -= 10;
	dna->posx += x;
	dna->posy += y;
}

void	zoom(int keycode, t_ml *dna)
{
	if (keycode == ZOOM_IN)
		dna->scale *= 1.2;
	if (keycode == ZOOM_OUT)
		dna->scale *= 0.8;
}

void	z_height(int keycode, t_ml *dna)
{
	if (keycode == UP_Z)
		dna->z_height += 0.4;
	if (keycode == DOWN_Z)
		dna->z_height -= 0.4;
}

void	reset(t_ml *dna)
{
	dna->posx = 0;
	dna->posy = 0;
	dna->z_height = 1;
	dna->scale = 1;
}

int		controller(int keycode, void *param)
{
	t_ml *dna;

	dna = param;
	clear_map(dna);
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		move(keycode, dna);
	if (keycode == ZOOM_IN || keycode == ZOOM_OUT)
		zoom(keycode, dna);
	if (keycode == UP_Z || keycode == DOWN_Z)
		z_height(keycode, dna);
	if (keycode == RESET)
		reset(dna);
	if (keycode == 53)
	{
		free_map(dna);
		exit(EXIT_SUCCESS);
	}
	draw_map(dna);
	return (0);
}
