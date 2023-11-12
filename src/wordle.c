/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:42:44 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/12 23:38:50 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	wipe(t_data *data)
{
	freeWords(data->words);
	freeChecker(data->checker);
}

void ctrlc(int sig) 
{
	while (sig)
		break ;
	printf(BOLD_RED);
    printf("\n\n        Please use ctrl+D to exit the game.\n");
	printf(DEFAULT);
	fflush(stdout);
	printf("\n                Guess the word:\n\n");
}

int	main(void)
{
	t_data		data;
	
	data.checker = malloc(sizeof(t_checker));
	if (!data.checker)
		return (1);
	*data.checker = NULL;
	signal(SIGINT, ctrlc);
	if (readFile(&data))
		return (1);
	getTodaysWord(&data);
	playGame(&data);
	wipe(&data);
	return (0);
}
