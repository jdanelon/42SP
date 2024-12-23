/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:07:53 by jdanelon          #+#    #+#             */
/*   Updated: 2019/12/06 16:56:41 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int r;

	r = 1;
	if (nb == 1)
		return (1);
	while (r <= nb / r)
	{
		if (r * r == nb)
			return (r);
		else if (r * r > nb)
			return (0);
		r++;
	}
	return (0);
}
