#include <unistd.h>

void	ft_print_sol(char *board)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		write(1, &board[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_sol_valid(char *board, int col)
{
	int	i;
	int	diff;

	i = 0;
	while (i < col)
	{
		diff = board[i] - board[col];
		if (diff == 0 || diff == i - col || diff == col - i)
			return (0);
		i++;
	}
	return (1);
}

void	main_loop(char *board, int *num_sol, int col)
{
	int	i;

	i = 0;
	if (col == 10)
	{
		ft_print_sol(board);
		(*num_sol)++;
		return ;
	}
	while (i < 10)
	{
		board[col] = i + '0';
		if (is_sol_valid(board, col))
			main_loop(board, num_sol, col + 1);
		i++;
	}
}

int ft_ten_queens_puzzle(void)
{
	int		i;
	int		num_sol;
	char	board[10];

	i = 0;
	num_sol = 0;
	while (i < 10)
	{
		board[i] = '0';
		i++;
	}
	main_loop(board, &num_sol, 0);
	return (num_sol);
}
