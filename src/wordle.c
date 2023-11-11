/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:42:44 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/11 17:13:02 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"

void	wipe(t_data *data)
{
	freeWords(data->words);
	if (data->checker.color)
		free(data->checker.color);
	if (data->checker.word)
		free(data->checker.word);
	if (data->checker.guess)
		free(data->checker.guess);
	if (data->todays_word)
		free(data->todays_word);
}

int	main(void)
{
	t_data		data;

	if (readFile(&data))
		return (1);
	if (check_word("yello", "yello", &data) == 1)
		return (wipe(&data), 1);
	getTodaysWord(&data);
	check_word(data.todays_word, "hello", &data);
	wipe(&data);
	return (0);
}
