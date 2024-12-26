#include "../includes/ft_display_file.h"

static int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

static void	display_file(int fd)
{
	char	c;

	while (read(fd, &c, 1))
		write(1, &c, 1);
	close(fd);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (1);
	}
	else if (argc > 2)
	{
		ft_putstr_fd("Too many arguments.\n", 2);
		return (1);
	}
	fd = open_file(argv[1]);
	if (fd == -1)
	{
		ft_putstr_fd("Cannot read file.\n", 2);
		return (1);
	}
	display_file(fd);
	return (0);
}
