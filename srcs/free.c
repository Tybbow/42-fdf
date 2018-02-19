/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:51:46 by tiskow            #+#    #+#             */
/*   Updated: 2018/02/19 20:14:48 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clear_map(t_ml *dna)
{
	dna->blank = 1;
	draw_map(dna);
	dna->blank = 0;
}

void	free_map(t_ml *dna)
{
	int i;

	i = 0;
	while (i < dna->map_w)
	{
		free(dna->map[i]);
		dna->map[i] = NULL;
		i++;
	}
	free(dna->map);
	dna->map = NULL;
}
