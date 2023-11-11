/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:42:44 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/11 14:42:12 by abied-ch         ###   ########.fr       */
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
	if (data->todaysWord)
		free(data->todaysWord);
}

int main()
{
	t_data		data;
	
	if (readFile(&data))
		return (1);
	if (check_word("yello", "yello", &data) == 1)
		return (wipe(&data), 1);
	getTodaysWord(&data);
	check_word(data.todaysWord, "hello", &data);
	wipe(&data);
    return 0;
}
