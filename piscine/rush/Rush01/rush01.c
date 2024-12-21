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

#include <stdio.h>

void	ft_putstr(char *str);

char	**init_view(char *in);
void	free_view(char **view);
char	**init_grid(char **view);
void	free_grid(char **grid);

static void	print(char **view, char **grid)
{
	printf("  %s\n", view[0]);
	printf("%c %s %c\n", view[2][0], grid[0], view[3][0]);
	printf("%c %s %c\n", view[2][1], grid[1], view[3][1]);
	printf("%c %s %c\n", view[2][2], grid[2], view[3][2]);
	printf("%c %s %c\n", view[2][3], grid[3], view[3][3]);
	printf("  %s\n", view[1]);
}

void	rush_01(char *str)
{
	char	**view;
	char	**grid;

	view = init_view(str);
	grid = init_grid(view);
	print(view, grid);
	free_grid(grid);
	free_view(view);
}
