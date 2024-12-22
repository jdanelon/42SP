/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:25:24 by jdanelon          #+#    #+#             */
/*   Updated: 2019/12/09 13:44:02 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_max_length(int size, char **strs, char *sep)
{
	int	i;
	int max;

	i = 0;
	max = 0;
	while (i < size)
	{
		max += ft_strlen(strs[i]);
		i++;
	}
	max += ((size - 1) * ft_strlen(sep)) + 1;
	return (max);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	int		aux;
	char	*concat;

	concat = (char *)malloc(ft_max_length(size, strs, sep));
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			concat[k++] = strs[i][j++];
		if (strs[i][j] == '\0' && k < ft_max_length(size, strs, sep) - 1)
		{
			aux = 0;
			while (aux < ft_strlen(sep))
				concat[k++] = sep[aux++];
		}
		i++;
	}
	concat[k] = '\0';
	return (concat);
}
