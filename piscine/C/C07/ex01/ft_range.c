/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:28:12 by jdanelon          #+#    #+#             */
/*   Updated: 2019/12/09 21:03:07 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*nums;

	i = 0;
	nums = (int *)malloc(4 * (max - min));
	if (min >= max)
		return (NULL);
	while (i < (max - min))
	{
		nums[i] = min + i;
		i++;
	}
	return (nums);
}
