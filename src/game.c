/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:46:44 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/11 12:17:17 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"

int	printGame(t_data *data)
{
	printf(BOLD);
    printf("                           /\\ \\ /\\_  \\           \n");
    printf(" __  __  __    ___   _ __  \\_\\ \\//\\  \\      __  \n");
    printf("/\\ \\/\\ \\/\\ \\  / __`\\/\\`'__\\/'_`  \\  \\ \\ \\   /'__`\\\n");
    printf("\\ \\ \\_/ \\_/ \\/\\ \\L\\  \\ \\ \\//\\  \\L \\ \\ \\_\\ \\_/\\  __/\n");
    printf(" \\ \\___x___/'\\ \\____/\\  \\_ \\ \\___,_\\/ \\____\\ \\____\\\n");
    printf("  \\/__//__/   \\/___/  \\/_/ \\/__,_ /\\/____/\\/____/\n");
	printf(DEFAULT);
	printf("%s", (*data->words)->word);
    return 0;
}

int	printWord(t_data *data)
{
	for (int i = 0; data->checker.guess[i]; i++)
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
	}
	printf("\n");
	return (0);
}
