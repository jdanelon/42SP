#include "../includes/ft_do-op.h"

static int	ft_negative(int n, int num)
{
	if (n % 2 != 0)
		num *= (-1);
	return (num);
}

static int	ft_is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	num;

	i = 0;
	n = 0;
	num = 0;
	while (str[i] != '\0' && ft_is_whitespace(str[i]) == 1)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n++;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (ft_negative(n, num));
}
