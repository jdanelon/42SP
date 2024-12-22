/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdanelon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:54:51 by jdanelon          #+#    #+#             */
/*   Updated: 2019/12/12 12:26:21 by jdanelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		++i;
	}
	return (0);
}

int	is_word(char c, char cbefore, char *charset)
{
	return (!is_separator(c, charset) && is_separator(cbefore, charset));
}

int	get_words_count(char *str, char *charset)
{
	int	i;
	int	words_count;

	i = 0;
	words_count = 0;
	while (str[i] != '\0')
	{
		if (is_word(str[i], str[i - 1], charset) || (!is_separator(str[i], charset) && i == 0))
			words_count++;
		i++;
	}
	return (words_count);
}

int	*get_words_size(char *str, char *charset)
{
	int	i;
	int	index;
	int	words_count;
	int	*words_size;

	i = 0;
	words_count = get_words_count(str, charset);
	words_size = malloc(words_count * 4);
	while (i <= words_count)
	{
		words_size[i] = 0;
		i++;
	}
	i = 0;
	index = 0;
	while (str[i] != '\0')
	{
		if (!is_separator(str[i], charset))
			words_size[index]++;
		else if (i > 0 && !is_separator(str[i - 1], charset))
			index++;
		i++;
	}
	return (words_size);
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	int		i;
	int		j;
	int		index;
	int		*words_size;

	words = malloc((get_words_count(str, charset) + 1) * 1);
	words_size = get_words_size(str, charset);
	index = 0;
	i = -1;
	j = 0;
	while (str[++i] != '\0')
	{
		if (!is_separator(str[i], charset))
		{
			if (i == 0 || is_word(str[i], str[i - 1], charset))
				words[index] = malloc(words_size[index] * 1);
			words[index][j] = str[i];
			words[index][++j] = '\0';
		}
		else if (i > 0 && !is_separator(str[i - 1], charset) && ++index)
			j = 0;
	}
	words[get_words_count(str, charset)] = 0;
	return (words);
}
