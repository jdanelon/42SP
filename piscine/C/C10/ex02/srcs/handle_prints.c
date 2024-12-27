#include "../includes/ft_tail.h"

void	handle_stdin(int bytes)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*whole_file;
	int		read_bytes;

	read_bytes = read(0, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	whole_file = ft_strdup(buffer);
	while (read_bytes > 0)
	{
		read_bytes = read(0, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		whole_file = ft_strjoin(whole_file, buffer);
	}
	if (ft_strlen(whole_file) < bytes)
		ft_putstr_fd(whole_file, 1);
	else
		ft_putstr_fd(&whole_file[ft_strlen(whole_file) - bytes], 1);
	free(whole_file);	
}

void	handle_file(int fd, int bytes)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*whole_file;
	int		read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	whole_file = ft_strdup(buffer);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		whole_file = ft_strjoin(whole_file, buffer);
	}
	if (ft_strlen(whole_file) < bytes)
		ft_putstr_fd(whole_file, 1);
	else
		ft_putstr_fd(&whole_file[ft_strlen(whole_file) - bytes], 1);
	free(whole_file);
	close(fd);
}
