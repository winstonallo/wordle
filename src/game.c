/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:46:44 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/11 21:34:34 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"
#include <stddef.h>
#include <stdio.h>

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
static t_checker	*newWord(char *guess, char *color, char *word)
{
	t_checker	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->word = word;
	new->guess = guess;
	new->color = color;
	new->next = NULL;
	return (new);
}

static void	checkerAddBack(t_checker **lst, t_checker *new_node)
{
	t_checker	*current;

	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

int	printWord(t_checker *node)
{
	printf(" ");
	for (size_t i = 0; node->guess[i]; i++)
	{
		printf(BOLD);
		if (node->color[i] == 'w')
			printf(GREY);
		if (node->color[i] == 'g')
			printf(GREEN);
		if (node->color[i] == 'y')
			printf(YELLOW);
		printf("%c", toupper(node->guess[i]));
		if (i < strlen(node->guess) - 1)
			printf(" ");
		printf(DEFAULT);
	}
	printf("\n\n");
	return (0);
}

int	playGame(t_data *data)
{
	int			tries;
	int 		i;
	t_checker	*new;
	t_checker	*head;
	char		temp[6];

	tries = 0;
	data->checker = malloc(sizeof(t_checker));
	if (!data->checker)
		return (1);
	*data->checker = NULL;
	while (tries < 6)
	{
		i = 0;
		if (tries == 0)
			printf("Guess the word:\n");
		else
			printf("Try again lol\n");
		scanf("%s", temp);
		printf("\r");
		tries++;
		new = newWord(NULL, NULL, NULL);
		if (check_word(data->todaysWord, temp, new) == CORRECT)
			return (printf("You win!\n"), 0); checkerAddBack(data->checker, new);
		head = *data->checker;
		while (i < tries)
		{
			printWord(head);
			head = head->next;
			i++;
		}
		while (i < 6)
		{
			printf(" _ _ _ _ _  \n\n");	
			i++;
		}
	}	
	return (0);
}
