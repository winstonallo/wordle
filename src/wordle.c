/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:42:44 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/11 23:30:00 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"

void	wipe(t_data *data)
{
	freeWords(data->words);
}

int	main(void)
{
	t_data		data;

	if (readFile(&data))
		return (1);
	// if (check_word("yello", "yello", data) == 1)
	// 	return (wipe(&data), 1);
	getTodaysWord(&data);
	playGame(&data);
	wipe(&data);
	return (0);
}
