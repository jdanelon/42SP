#include "../includes/ft_do-op.h"

void	add(int n1, int n2)
{
	int	result;

	result = n1 + n2;
	ft_putnbr(result);
}

void	subtract(int n1, int n2)
{
	int	result;

	result = n1 - n2;
	ft_putnbr(result);
}

void	divide(int n1, int n2)
{
	if (n2 != 0)
	{
		int	result;

		result = n1 / n2;
		ft_putnbr(result);
	}
	else
	{
		ft_putstr("Stop : division by zero");
	}
}

void	multiply(int n1, int n2)
{
	int	result;

	result = n1 * n2;
	ft_putnbr(result);
}

void	modulo(int n1, int n2)
{
	if (n2 != 0)
	{
		int	result;

		result = n1 % n2;
		ft_putnbr(result);
	}
	else
	{
		ft_putstr("Stop : modulo by zero");
	}
}
