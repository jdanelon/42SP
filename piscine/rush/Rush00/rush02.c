/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshiraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:17:15 by jshiraza          #+#    #+#             */
/*   Updated: 2019/11/24 17:02:03 by jshiraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

static void	print_first_line(int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (i == 0)
			ft_putchar('A');
		else if(i == cols - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
		i += 1;
	}
	ft_putchar('\n');
}

static void	print_middle_lines(int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (i == 0 || i == cols - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
		i += 1;
	}
	ft_putchar('\n');
}

static void	print_last_line(int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (i == 0)
			ft_putchar('C');
		else if (i == cols - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		i += 1;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	rows;

	rows = 0;
	if (x == 0)
		return ;
	while (rows < y)
	{
		if (rows == 0)
			print_first_line(x);
		else if (rows == y - 1)
			print_last_line(x);
		else
			print_middle_lines(x);
		rows += 1;
	}
}
