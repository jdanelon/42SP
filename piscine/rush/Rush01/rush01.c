/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 10:22:10 by jdanelon          #+#    #+#             */
/*   Updated: 2019/12/01 18:39:13 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	print_sol(char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(grid[i][j]);
			if (j != 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

static void	run_main_loop(char **view, char **grid, int row, int col, int *num_sols)
{
	int	j;

	j = 0;
	if (row == 4)
	{
		if (validate_col(view, grid) == OK)
		{
			print_sol(grid);
			(*num_sols)++;
			return ;
		}
	}
	else if (col == 4)
	{
		if (validate_row(view[2][row], grid[row], view[3][row]) == OK)
			run_main_loop(view, grid, row + 1, 0, num_sols);
	}
	while (j < 4 && row < 4 && col < 4)
	{
		grid[row][col] = j + '1';
		if (validate_cell(grid, row, col) == OK)
			run_main_loop(view, grid, row, col + 1, num_sols);
		j++;
	}
}

void	rush_01(char *str)
{
	int		num_sols;
	char	**view;
	char	**grid;

	num_sols = 0;
	view = init_view(str);
	grid = init_grid();
	run_main_loop(view, grid, 0, 0, &num_sols);
	if (num_sols == 0)
		ft_putstr("Error\n");
	free_grid(grid);
	free_view(view);
}
