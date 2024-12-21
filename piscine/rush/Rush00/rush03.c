/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshiraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:38:54 by jshiraza          #+#    #+#             */
/*   Updated: 2019/11/24 15:22:35 by jshiraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int i;
	int j;

	i = 1;
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			if ((i == 1 || i == y) && (j == 1))
				ft_putchar('A');
			if (((i == 1 || i == y) && (j == x)) && x != 1)
				ft_putchar('C');
			if ((i == 1 || i == y) && (j > 1 && j < x))
				ft_putchar('B');
			if ((i > 1 && i < y) && (j == 1 || j == x))
				ft_putchar('B');
			if ((i > 1 && i < y) && (j > 1 && j < x))
				ft_putchar(' ');
			j += 1;
		}
		ft_putchar('\n');
		i += 1;
	}
}
