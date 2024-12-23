#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_count0(int a[10], int idx)
{
	int i;
	int cd0;

	i = 0;
	cd0 = 0;
	while (i < idx)
	{
		if (a[i] != 48)
			cd0++;
		i++;
	}
	return (cd0);
}

void	ft_print_no0(int a[10])
{
	int		j;
	char	num;
	int		count0;

	j = 1;
	while (j <= 10)
	{
		count0 = ft_count0(a, j);
		if (count0 != 0)
		{
			num = (char)a[j - 1];
			ft_putstr(&num);
		}
		j++;
	}
}

void	ft_putnbr(int nb)
{
	int				i;
	int				val;
	unsigned int	n;
	int				a[10];

	i = 1;
	val = 1000000000;
	if (nb < 0)
	{
		ft_putstr("-");
		n = -nb;
	}
	else
		n = nb;
	if (n == 0)
		ft_putstr("0");
	while (i <= 10)
	{
		a[i - 1] = n / val;
		a[i - 1] += 48;
		n = n % val;
		val /= 10;
		i++;
	}
	ft_print_no0(a);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		i++;
	}
}
