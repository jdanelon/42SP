/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:15:12 by jdanelon          #+#    #+#             */
/*   Updated: 2019/12/09 15:47:28 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_check_error(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || ft_is_whitespace(base[i]) == 1)
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

int	ft_get_index(char *str, int i, char *base)
{
	int	lim;
	int	j;
	int	count;

	lim = i;
	while (str[lim] != '\0')
	{
		j = 0;
		count = 0;
		while (base[j] != '\0')
		{
			if (str[lim] == base[j])
				count++;
			j++;
		}
		if (count == 0)
			break ;
		lim++;
	}
	return (lim);
}

int	ft_convert(char *str, int i, int lim, char *base)
{
	int	aux;
	int	num;
	int	len;

	num = 0;
	len = 0;
	while (base[len] != '\0')
		len++;
	while (i < lim)
	{
		aux = 0;
		while (str[i] != base[aux])
			aux++;
		num = (num * len) + aux;
		i++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	end;
	int	nbr;

	i = 0;
	n = 0;
	if (ft_check_error(base) == 1)
		return (0);
	while (str[i] != '\0' && ft_is_whitespace(str[i]) == 1)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n++;
		i++;
	}
	end = ft_get_index(str, i, base);
	nbr = ft_convert(str, i, end, base);
	if (n % 2 != 0)
		nbr *= (-1);
	return (nbr);
}
