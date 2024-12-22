/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:47:36 by jdanelon          #+#    #+#             */
/*   Updated: 2019/12/05 15:07:54 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nbr)
{
	int i;

	i = 2;
	if (nbr < 2)
		return (0);
	if (nbr % 2 == 0 && nbr != 2)
		return (0);
	while (i <= nbr / i)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int ret;
	int ver;

	ret = nb;
	ver = 0;
	while (ver == 0)
	{
		ver = ft_is_prime(ret);
		ret++;
	}
	return (ret - 1);
}
