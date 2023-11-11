/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:46:44 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/11 17:11:34 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"

int	print_game(t_data *data)
{
	printf(BOLD);
    printf("                           /\\ \\ /\\_  \\           \n");
    printf(" __  __  __    ___   _ __  \\_\\ \\//\\  \\      __  \n");
    printf("/\\ \\/\\ \\/\\ \\  / __`\\/\\`'__\\/");
	printf("'_`  \\  \\ \\ \\   /'__`\\\n");
    printf("\\ \\ \\_/ \\_/ \\/\\ \\L\\  \\ \\ \\//");
	printf("\\  \\L \\ \\ \\_\\ \\_/\\  __/\n");
	printf(" \\ \\___x___/'\\ \\____/\\  \\_ \\");
    printf(" \\___,_\\/ \\____\\ \\____\\\n");
    printf("  \\/__//__/   \\/___/  \\/_/ \\/__,_ /\\/____/\\/____/\n");
	printf(DEFAULT);
	printf("%s", (*data->words)->word);
	return (0);
}

int	print_word(t_data *data)
{
	int	i;

	i = 0;
	while (data->checker.guess[i])
	{
		if (data->checker.color[i] == 'w')
			printf(GREY);
		if (data->checker.color[i] == 'g')
			printf(GREEN);
		if (data->checker.color[i] == 'y')
			printf(YELLOW);
		printf(" ");
		printf("%c", toupper(data->checker.guess[i]));
		printf(" ");
		printf(DEFAULT);
		i++;
	}
	printf("\n");
	return (0);
}
