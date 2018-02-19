/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:48:07 by tiskow            #+#    #+#             */
/*   Updated: 2018/02/19 21:00:06 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <unistd.h>
#include <stdlib.h>

void	error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

void    display_menu(t_ml *dna)
{
        mlx_string_put(dna->mlx, dna->win, 20, 20, 0x00BFA5,
                "fleche directionelle pour deplacer la camera");
        mlx_string_put(dna->mlx, dna->win, 20, 40, 0x00B8D4,
                "[+] et [-] pour gerer le zoom");
        mlx_string_put(dna->mlx, dna->win, 20, 60, 0xCDDC39,
                "[d] et [f] pour gerer la hauteur");
		mlx_string_put(dna->mlx, dna->win, 20, 80, 0xCD0039,
                "[q] reset ");
        mlx_string_put(dna->mlx, dna->win, 20, 100, 0x0091EA,
                "ESC pour quitter");
}

void	z_limits(t_ml *dna, int z)
{
	dna->max_z = (dna->max_z < z) ? z : dna->max_z;
	dna->min_z = (dna->min_z > z) ? z : dna->min_z;
}

int		main(int argc, char **argv)
{
	t_ml dna;
	void *mlx;
	void *win;

	init(&dna);
	if (argc == 2)
		load_map(argv[1], &dna);
	else
		error("usage: fdf input_file\n");
	mlx = mlx_init();
	if (!mlx)
		return (0);
	win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	dna.mlx = mlx;
	dna.win = win;
	display_menu(&dna);
	draw_map(&dna);
	mlx_hook(win, 2, 3, &controller, &dna);
	mlx_loop(mlx);
	return (0);
}
