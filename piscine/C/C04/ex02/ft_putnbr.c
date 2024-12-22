/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:34:22 by jdanelon          #+#    #+#             */
/*   Updated: 2019/12/04 18:54:47 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_sign(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	return (n);
}

int	ft_count0(int a[10], int idx)
{
	int i;
	int cd0;

	i = 0;
	cd0 = 0;
	while (i < idx)
	{
		if (a[i] != 48)
			cd0++;
		i++;
	}
	return (cd0);
}

void	ft_print_no0(int a[10])
{
	int j;
	int count0;

	j = 1;
	while (j <= 10)
	{
		count0 = ft_count0(a, j);
		if (count0 != 0)
			ft_putchar(a[j - 1]);
		j++;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int	n;
	int				i;
	int				val;
	int				a[10];

	n = ft_sign(nb);
	i = 1;
	val = 1000000000;
	if (n == 0)
		ft_putchar('0');
	while (i <= 10)
	{
		a[i - 1] = n / val;
		a[i - 1] += 48;
		n = n % val;
		val /= 10;
		i++;
	}
	ft_print_no0(a);
}
