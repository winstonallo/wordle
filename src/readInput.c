/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readInput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:05:57 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/11 12:43:38 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"

int	main(void)
{
	char	guess[7];

	printf("Guess: ");
	scanf("%6s", guess);
	if (strlen(guess) != 5)
		printf("wrong length, guess again\n");
	if (!is_word()) //todo
		printf("not a word, guess again")

	printf("%s\n", guess);
}