/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouad <mouad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:21:43 by mouad             #+#    #+#             */
/*   Updated: 2024/11/11 11:52:22 by mouad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, char delimiter)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == delimiter)
			i++;
		if (s[i] && s[i] != delimiter)
			count++;
		while (s[i] && s[i] != delimiter)
			i++;
	}
	return (count);
}

static char	**allocate_array(int word_count)
{
	char	**words;

	words = malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	words[word_count] = NULL;
	return (words);
}

char	*get_word(char *s, int *i, char delimiter)
{
	int		start;
	int		len;
	char	*word;
	int		k;

	start = *i;
	while (s[*i] && s[*i] == delimiter)
		(*i)++;
	if (s[*i] == '\0')
		return (NULL);
	while (s[*i] && s[*i] != delimiter)
		(*i)++;
	len = *i - start;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	k = 0;
	while (k < len)
	{
		word[k] = s[start + k];
		k++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *s, char delimiter)
{
	int		i;
	int		j;
	char	**words;
	char	*word;

	i = 0;
	j = 0;
	words = allocate_array(count_words(s, delimiter));
	if (!words)
		return (NULL);
	while (s[i])
	{
		word = get_word(s, &i, delimiter);
		if (word)
		{
			words[j] = word;
			j++;
		}
	}
	return (words);
}
