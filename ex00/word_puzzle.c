/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_puzzle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaito <mnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:17:55 by mnaito            #+#    #+#             */
/*   Updated: 2024/06/27 17:03:50 by mnaito           ###   ########.fr       */
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

/* test function */

//static void test_word_puzzle(size_t N, char **words)
//{
//    printf("Input: N = %zu, words = {", N);
//    for (size_t i = 0; i < N; i++) {
//        printf("\"%s\"", words[i]);
//        if (i < N - 1)
//            printf(", ");
//    }
//    printf("} Output: %d\n", word_puzzle(N, words));
//}

//int main() {
//    size_t N1 = 2;
//    char *words1[] = {"dash", "hard"};
//    test_word_puzzle(N1, words1);

//    size_t N2 = 3;
//    char *words2[] = {"dash", "too", "hard"};
//    test_word_puzzle(N2, words2);

//    size_t N3 = 4;
//    char *words3[] = {"apple", "elephant", "tiger", "rabbit"};
//    test_word_puzzle(N3, words3);

//    size_t N4 = 5;
//    char *words4[] = {"cat", "tiger", "rabbit", "bat", "tiger"};
//    test_word_puzzle(N4, words4);

//    return 0;
//}

 