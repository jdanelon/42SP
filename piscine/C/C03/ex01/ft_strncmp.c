/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:02:52 by jdanelon          #+#    #+#             */
/*   Updated: 2019/12/04 14:12:22 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char)s1[i] != '\0' && (unsigned char)s2[i] != '\0') &&
			i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (((unsigned int)s1[i] != (unsigned int)s2[i]) && i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
