/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:51:12 by tiskow            #+#    #+#             */
/*   Updated: 2018/02/19 20:14:39 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init(t_ml *dna)
{
	dna->origin.x = SCREEN_WIDTH / 2;
	dna->origin.y = 50;
	dna->posx = 0;
	dna->posy = 0;
	dna->z_height = 1;
	dna->scale = 1.0;
	dna->rot = 1.0;
	dna->max_z = 0;
	dna->min_z = 0;
}
