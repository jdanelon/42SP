/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 10:04:31 by jdanelon          #+#    #+#             */
/*   Updated: 2019/11/30 20:13:22 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

static int	check_for_error(char *in)
{
	int i;

	i = 0;
	while (in[i] != '\0')
	{
		if (i % 2 != 0 && in[i] != ' ')
			break ;
		else if (i % 2 == 0 && (in[i] < '1' || in[i] > '4'))
			break ;
		i++;
	}
	if (i == 31 && in[i] == '\0')
		return (OK);
	return (ERROR);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr("Error\n");
	else
	{
		if (check_for_error(argv[1]) == OK)
			rush_01(argv[1]);
		else
			ft_putstr("Error\n");
	}
	return (0);
}
