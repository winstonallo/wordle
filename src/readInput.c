/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readInput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:05:57 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/11 13:34:25 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"

int	is_word(t_words *words, char *str)
{
	while (words)
	{
		if (strncmp(words->word, str, 5) == 0)
			return (1);
		words = words->next;
	}
	return (0);
}

int	main(void)
{
	char	guess[7];

	printf("Guess: ");
	scanf("%6s", guess);
	if (strlen(guess) != 5)
		printf("wrong length\n");
	if (!is_word(data.words, guess))
		printf("not a word\n");
	printf("%s\n", guess);
}