/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:57:40 by jdanelon          #+#    #+#             */
/*   Updated: 2019/11/27 11:29:45 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char *comb, int len)
{
	int	i;

	i = 0;
	while (comb[i] != '\0')
	{
		ft_putchar(comb[i]);
		i++;
	}
	if (comb[0] != 10 - len + '0' || comb[len - 1] != 9 + '0')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	else
		ft_putchar('\n');
}

void	ft_loop(char *comb, int len)
{
	int	i;
	int	j;

	i = 0;
	while (comb[0] <= 10 - len + '0' || comb[len - 1] <= 9 + '0')
	{
		if (i == len - 1)
		{
			while (comb[i] <= 9 + '0')
			{
				ft_print(comb, len);
				comb[i]++;
			}
			j = 0;
			while (j < len)
			{
				comb[j]++;
				j++;
			}
			comb[i] = comb[i - 1] + 1;
			i = -1;
		}
		i++;
		if (len == 1)
			break ;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	comb[n];

	i = 0;
	while (i < n)
	{
		comb[i] = i + '0';
		i++;
	}
	comb[i] = '\0';
	if (n > 0 && n < 10)
		ft_loop(comb, n);
}
