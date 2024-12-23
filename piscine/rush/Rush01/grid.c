#include "rush01.h"

char	**init_grid(void)
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
