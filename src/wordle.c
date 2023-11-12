/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:42:44 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/12 12:04:15 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"

void	wipe(t_data *data)
{
	freeWords(data->words);
	freeChecker(data->checker);
}

int	main(void)
{
	t_data		data;

	if (readFile(&data))
		return (1);
	printWordle();
	getTodaysWord(&data);
	playGame(&data);
	wipe(&data);
	return (0);
}
