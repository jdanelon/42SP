#ifndef	FT_TAIL_H
# define FT_TAIL_H

# define BUFFER_SIZE 32

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <libgen.h>
# include <errno.h>

/* utils.c */
void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);

/* handle_prints.c */
void	handle_stdin(int bytes);
void	handle_file(int fd, int bytes);

#endif
