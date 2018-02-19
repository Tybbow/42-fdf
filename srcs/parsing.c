/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:50:24 by tiskow            #+#    #+#             */
/*   Updated: 2018/02/19 20:14:31 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		check_map(char *buff)
{
	check_sign(buff);
	check_layout(buff);
}

void		check_sign(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (!ft_strchr(SIGN, buff[i]) && !ft_isdigit(buff[i]))
			error("File Sign Error\n");
		i++;
	}
}

void		check_layout(char *buff)
{
	int i;
	int j;
	int width;

	i = -1;
	j = 0;
	width = 0;
	while (buff[++i] != '\n')
		if (ft_isdigit(buff[i]) && (buff[i + 1] == ' ' || buff[i + 1] == '\n'))
			width++;
	i++;
	while (buff[i])
	{
		if (ft_isdigit(buff[i]) && (buff[i + 1] == ' ' || buff[i + 1] == '\n'))
			j++;
		if (buff[i] == '\n')
		{
			if (j != width)
				error("error layout\n");
			j = 0;
		}
		i++;
	}
}

int			range(int nb)
{
	if (nb > RANGE_MAX)
		return (RANGE_MAX);
	else if (nb < -RANGE_MAX)
		return (-RANGE_MAX);
	return (nb);
}
