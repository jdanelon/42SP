#include "../includes/ft_cat.h"

static void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

static void	handle_stdin(void)
{
	char	buf[32];
	int		bytes_read;

	bytes_read = read(0, buf, 32);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		ft_putstr_fd(buf, 1);
		bytes_read = read(0, buf, 32);
	}
}

static void	handle_error(char *file, int *num_errors)
{
	ft_putstr_fd("ft_cat: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	(*num_errors)++;
}

static void	display_file(int fd)
{
	char	buf[32];
	int		bytes_read;

	bytes_read = read(fd, buf, 32);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		ft_putstr_fd(buf, 1);
		bytes_read = read(fd, buf, 32);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;
	int	num_errors;

	i = 1;
	num_errors = 0;
	if (argc == 1)
		handle_stdin();
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (errno != 0)
			handle_error(argv[i], &num_errors);
		else
			display_file(fd);
		errno = 0;
		i++;
	}
	if (num_errors != 0)
		return (1);
	return (0);
}
