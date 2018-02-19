/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:50:10 by tiskow            #+#    #+#             */
/*   Updated: 2018/02/19 20:15:09 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		color(t_ml *dna, float z)
{
	int		ret;
	float	factor;
	int		green;
	int		blue;

	if (dna->blank)
		return (0x00000000);
	if ((dna->max_z - dna->min_z) != 0)
		factor = 255 / (dna->max_z - dna->min_z);
	else
		factor = 0;
	green = 255 - ((int)(factor * z));
	blue = (int)(factor * z);
	ret = 0x00FF0000;
	green = green << 8;
	ret = ret | green;
	ret = ret | blue;
	return (ret);
}
