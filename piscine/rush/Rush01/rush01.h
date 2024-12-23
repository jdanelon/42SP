#ifndef RUSH01_H
# define RUSH01_H

# define OK 0
# define ERROR 1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* main.c */
void    ft_putchar(char c);
void	ft_putstr(char *str);

/* rush01.c */
void	rush_01(char *str);

/* view.c */
char	**init_view(char *in);
void	free_view(char **view);

/* grid.c */
char	**init_grid(void);
void	free_grid(char **grid);

/* validate_grid.c */
int		validate_col(char **view, char **grid);
int		validate_row(char left_val, char *grid_row, char right_val);
int 	validate_cell(char **grid, int row, int col);

#endif
