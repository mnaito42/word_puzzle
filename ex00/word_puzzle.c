/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_puzzle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaito <mnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:17:55 by mnaito            #+#    #+#             */
/*   Updated: 2024/06/27 16:53:48 by mnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

int word_puzzle(size_t N, char **words);

static int	is_valid_word(char *word)
{
	size_t	i;
	char	ch;

	i = 0;
	while (word[i])
	{
		ch = word[i];
		if (!('a' <= ch && ch <= 'z'))
			return (0);
		i++;
	}
	if (i < 1 || 100 < i)
		return (0);
	return (1);
}

static char	get_last_ch(char *word)
{
	int	i;

	i = 0;
	while (word[i])
		i++;
	return (word[i - 1]);
}

int word_puzzle(size_t N, char **words)
{
	size_t	i;
	char	last_ch;
	char	first_ch;

	if (N < 2 || 100000 < N)
		return (0);
	i = 0;
	while (i < N)
	{
		if (!words[i] || !is_valid_word(words[i]))
			return (0);
		if (i != 0)
		{
			first_ch = words[i][0];
			if (last_ch != first_ch)
				return (0);
		}
		last_ch = get_last_ch(words[i]);
		i++;
	}
	return (1);
}

int main() {
    size_t	N1;
	N1 = 2;
    char *words1[] = {"dash", "hard"};
    printf("Input: N = %zu, words = {\"%s\", \"%s\"} Output: %d\n", N1, words1[0], words1[1], word_puzzle(N1, words1));

    size_t N2 = 3;
    char *words2[] = {"dash", "too", "hard"};
    printf("Input: N = %zu, words = {\"%s\", \"%s\", \"%s\"} Output: %d\n", N2, words2[0], words2[1], words2[2], word_puzzle(N2, words2));

    return (0);
}

 