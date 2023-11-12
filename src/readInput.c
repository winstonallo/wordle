/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readInput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:05:57 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/12 10:03:58 by jkoupy           ###   ########.fr       */
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