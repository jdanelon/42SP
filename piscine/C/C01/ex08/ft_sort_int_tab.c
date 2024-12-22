/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:26:01 by jdanelon          #+#    #+#             */
/*   Updated: 2019/11/28 09:26:14 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int t;

	i = 1;
	while (i < size)
	{
		if (tab[i] < tab[i - 1])
		{
			t = tab[i - 1];
			tab[i - 1] = tab[i];
			tab[i] = t;
			i = 1;
		}
		else
			i++;
	}
}