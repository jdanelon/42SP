#include "../includes/ft_do-op.h"

static int	ft_strcmp(char *str, char c)
{
	if (str[1] != '\0')
		return (1);
	if (str[0] != c)
		return (1);
	return (0);
}

static int	get_operation(char *op)
{
	int		i;
	char	operations[] = "+-/*%";

	i = 0;
	while (i < 5)
	{
		if (ft_strcmp(op, operations[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

static void	calculate(int n1, int num_op, int n2)
{
	void	(*operations[5])(int, int);

	operations[0] = &add;
	operations[1] = &subtract;
	operations[2] = &divide;
	operations[3] = &multiply;
	operations[4] = &modulo;
	if (num_op == 5)
	{
		ft_putstr("0\n");
		return ;
	}
	operations[num_op](n1, n2);
	ft_putstr("\n");
}

int	main(int argc, char **argv)
{
	int	num_op;
	int	n1;
	int	n2;

	if (argc != 4)
		return (0);
	num_op = get_operation(argv[2]);
	n1 = ft_atoi(argv[1]);
	n2 = ft_atoi(argv[3]);
	calculate(n1, num_op, n2);
	return (0);
}
