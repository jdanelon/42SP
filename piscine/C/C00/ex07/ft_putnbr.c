/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:46:18 by jdanelon          #+#    #+#             */
/*   Updated: 2019/11/27 09:40:43 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_sign(int nb)
{
	int unsigned	n;

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
	int	cd0;
	int	i;

	i = 0;
	cd0 = 0;
	while (i < idx)
	{
		if (a[i] != '0')
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
	int				i;
	int unsigned	n;
	int				a[10];
	int				val;

	i = 1;
	val = 1000000000;
	n = ft_sign(nb);
	if (n == 0)
		ft_putchar('0');
	while (i <= 10)
	{
		a[i - 1] = n / val;
		a[i - 1] += '0';
		n = n % val;
		val /= 10;
		i++;
	}
	ft_print_no0(a);
}
