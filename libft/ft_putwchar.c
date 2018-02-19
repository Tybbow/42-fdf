/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:28:52 by tiskow            #+#    #+#             */
/*   Updated: 2018/02/19 20:17:01 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t c)
{
	if (c < 0x7f)
		ft_putchar(c);
	else if (c < 0x800)
	{
		ft_putchar((c >> 6) | 0xC0);
		ft_putchar((c & 0x3f) | 0x80);
	}
	else if (c < 0x10000)
	{
		ft_putchar((c >> 12) | 0xE0);
		ft_putchar(((c >> 6) & 0x3f) | 0x80);
		ft_putchar((c & 0x3f) | 0x80);
	}
	else if (c < 0x200000)
	{
		ft_putchar((c >> 18) | 0xF0);
		ft_putchar(((c >> 12) & 0x3f) | 0x80);
		ft_putchar(((c >> 6) & 0x3f) | 0x80);
		ft_putchar((c & 0x3f) | 0x80);
	}
}
