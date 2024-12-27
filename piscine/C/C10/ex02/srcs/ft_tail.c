#include "../includes/ft_tail.h"

static int	validate_inputs(int num_args, char **argv, int *num_chars)
{
	if (num_args == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (num_args == 2)
	{
		ft_putstr_fd("ft_tail: option requires an argument -- 'c'\n", 2);
		return (1);
	}
	*num_chars = ft_atoi(argv[2]);
	if (*num_chars == -1)
	{
		ft_putstr_fd("ft_tail: invalid number of bytes: '", 2);
		ft_putstr_fd(argv[2], 2);
		ft_putstr_fd("'\n", 2);
		return (1);
	}
	return (0);
}

static void	display_header(char *filename)
{
	ft_putstr_fd("==> ", 1);
	ft_putstr_fd(filename, 1);
	ft_putstr_fd(" <==\n", 1);
}

static void	handle_args(int num_args, char *arg, int idx, int *num_errors, int bytes)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (errno != 0)
	{
		ft_putstr_fd("ft_tail: cannot open '", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("' for reading: No such file or directory\n", 2);
		(*num_errors)++;
	}
	else
	{
		if (num_args > 4)
			display_header(arg);
		handle_file(fd, bytes);
		if (idx != num_args - 1)
			ft_putstr_fd("\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	num_chars;
	int	num_errors;

	i = 3;
	num_errors = 0;
	if (validate_inputs(argc, argv, &num_chars) == 1)
		return (1);
	if (argc == 3)
		handle_stdin(num_chars);
	while (i < argc)
	{
		handle_args(argc, argv[i], i, &num_errors, num_chars);
		errno = 0;
		i++;
	}
	if (num_errors != 0)
		return (1);
	return (0);
}
