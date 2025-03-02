#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*matrix;

	i = 0;
	matrix = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		matrix[i] = f(tab[i]);
		i++;
	}
	return (matrix);
}
