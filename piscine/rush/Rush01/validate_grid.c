#include "rush01.h"

static void	vals_cols(char **grid, int *count_up, int *count_down, int col)
{
	int		i;
	char	max_up;
	char	max_down;

	i = 0;
	max_up = '0';
	max_down = '0';
	while (i < 4)
	{
		if (grid[i][col] > max_up)
		{
			max_up = grid[i][col];
			(*count_up)++;
		}
		if (grid[3 - i][col] > max_down)
		{
			max_down = grid[3 - i][col];
			(*count_down)++;
		}
		i++;
	}
}

int  validate_col(char **view, char **grid)
{
	int		j;
	int		count_up;
	int		count_down;

	j = 0;
	while (j < 4)
	{
		count_up = 0;
		count_down = 0;
		vals_cols(grid, &count_up, &count_down, j);
		if (count_up != view[0][j] - '0' || count_down != view[1][j] - '0')
			return (ERROR);
		j++;
		
	}
	return (OK);
}

int  validate_row(char left_val, char *grid_row, char right_val)
{
	int		j;
	char	max_left;
	int		count_left;
	char	max_right;
	int		count_right;

	j = 0;
	max_left = '0';
	count_left = 0;
	max_right = '0';
	count_right = 0;
	while (j < 4)
	{
		if (grid_row[j] > max_left)
		{
			max_left = grid_row[j];
			count_left++;
		}
		if (grid_row[3 - j] > max_right)
		{
			max_right = grid_row[3 - j];
			count_right++;
		}
		j++;
	}
	if (count_left != left_val - '0' || count_right != right_val - '0')
		return (ERROR);
	return (OK);
}

int	validate_cell(char **grid, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (grid[row][i] == grid[row][col])
			return (ERROR);
		i++;
	}
	i = 0;
	while (i < row)
	{
		if (grid[i][col] == grid[row][col])
			return (ERROR);
		i++;
	}
	return (OK);
}
