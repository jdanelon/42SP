/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:02:15 by jdanelon          #+#    #+#             */
/*   Updated: 2019/12/12 17:42:34 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_convert_to_hex(int h)
{
	char	*pattern;

	pattern = "0123456789abcdef";
	if (h > 16)
	{
		ft_convert_to_hex(h / 16);
		ft_convert_to_hex(h % 16);
	}
	else
		ft_putchar(pattern[h]);
}

void	ft_putstr_non_printable(char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if ((unsigned char)src[i] < 32 || (unsigned char)src[i] > 126)
		{
			ft_putchar('\\');
			if ((unsigned char)src[i] < 16)
				ft_putchar('0');
			ft_convert_to_hex((unsigned char)src[i]);
		}
		else
			ft_putchar((unsigned char)src[i]);
		i++;
	}
}
