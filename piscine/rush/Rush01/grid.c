#include <stdlib.h>

static char	**found_4(int i, int j, char **grid)
{
	int		idx;
	char	val;

	idx = 0;
	while (idx < 4)
	{
		val = '1' + idx;
		if (i == 0)
			grid[idx][j] = val;
		else if (i == 1)
			grid[3 - idx][j] = val;
		else if (i == 2)
			grid[j][idx] = val;
		else if (i == 3)
			grid[j][3 - idx] = val;
		idx++;
	}
	return (grid);
}

static char	**found_1(int i, int j, char **grid)
{
	if (i == 0)
		grid[0][j] = '4';
	else if (i == 1)
		grid[3][j] = '4';
	else if (i == 2)
		grid[j][0] = '4';
	else if (i == 3)
		grid[j][3] = '4';
	return (grid);
}

static char	**fill_grid_from_view(char **view, char **grid)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (view[i][j] == '4')
				grid = found_4(i, j, grid);
			else if (view[i][j] == '1')
				grid = found_1(i, j, grid);
			j++;
		}
		i++;
	}
	return (grid);
}

char	**init_grid(char **view)
{
	char	**grid;
	int		i;
	int		j;

	grid = (char **)malloc(5 * sizeof(char *));
	i = 0;
	while (i < 4)
	{
		grid[i] = (char *)malloc(5 * sizeof(char));
		j = 0;
		while (j < 4)
		{
			grid[i][j] = '0';
			j++;
		}
		grid[i][j] = '\0';
		i++;
	}
	grid[i] = '\0';
	grid = fill_grid_from_view(view, grid);
	return (grid);
}

void	free_grid(char **grid)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
