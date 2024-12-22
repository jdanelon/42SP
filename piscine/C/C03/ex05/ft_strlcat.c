/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:47:04 by jdanelon          #+#    #+#             */
/*   Updated: 2019/12/03 14:51:40 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	res;

	i = 0;
	len = 0;
	res = 0;
	while (dest[len] != '\0')
		len++;
	while (src[res] != '\0')
		res++;
	if (size <= len)
		res += size;
	else
		res += len;
	if (size == 0)
		return (res);
	while (src[i] != '\0' && len + i < size - 1)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (res);
}
