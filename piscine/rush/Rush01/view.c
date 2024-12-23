#include "rush01.h"

char	**init_view(char *in)
{
	char	**view;
	int		i;
	int		j;

	view = (char **)malloc(5 * sizeof(char *));
	i = 0;
	while (i < 4)
	{
		view[i] = (char *)malloc(5 * sizeof(char));
		j = 0;
		while (j < 4)
		{
			view[i][j] = in[i * 8 + j * 2];
			j++;
		}
		view[i][j] = '\0';
		i++;
	}
	view[i] = '\0';
	return (view);
}

void	free_view(char **view)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		free(view[i]);
		i++;
	}
	free(view);
}
