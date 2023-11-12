/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:46:44 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/12 11:46:54 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"
#include <stddef.h>
#include <stdio.h>

int	printWordle(void)
{
	printf(BOLD);
	printf("                             __   ___\n");
	printf("                            /\\ \\ /\\_ \\\n");
	printf("  __  __  __    ___   _ __  \\_\\ \\\\//\\ \\      __\n");
	printf(" /\\ \\/\\ \\/\\ \\  / __`\\/\\`'__\\/'_` \\ \\ \\ \\   /'__`\\\n");
	printf(" \\ \\ \\_/ \\_/ \\/\\ \\L\\ \\ \\ \\//\\ \\L\\ \\ \\_\\ \\_/\\  __/ \n");
	printf("  \\ \\___x___/'\\ \\____/\\ \\_\\\\ \\___,_\\/\\____\\ \\____\\\n");
	printf("   \\/__//__/   \\/___/  \\/_/ \\/__,_ /\\/____/\\/____/\n");
	printf("                            by abied-ch and jkoupy\n\n");
	printf(DEFAULT);
	return (0);
}
static t_checker	*newChecker(char *guess, char *color, char *word)
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
	printf("\n                     ");
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
	printf("\n");
	return (0);
}

int	playGame(t_data *data)
{
	int			tries;
	int 		i;
	t_checker	*new;
	t_checker	*head;
	char		temp[8];

	tries = -1;
	data->checker = malloc(sizeof(t_checker));
	if (!data->checker)
		return (1);
	*data->checker = NULL;
	while (tries < 6)
	{
		i = 0;
		if (tries == -1)
		{
			printf(BOLD);
			printf("            Welcome to the game of Wordle,\n");
			printf("     you have 6 guesses to guess the word of today.\n\n");
			printf(DEFAULT);
			printf("               Guess the word: ");
			tries++;
		}
		else
		{
			printf(BOLD);
			printf("               You have ");
			printf(BOLD_GREEN);
			printf("%d", 6 - tries);
			printf(DEFAULT);
			printf(BOLD);
			printf(" attempts left.\n\n");
			printf(DEFAULT);
			printf("               Guess the word: ");	
		}
		scanf("%6s", temp);
		
		if (strlen(temp) != 5)
		{
			printf(RED);
			printf(BOLD);
			printf("               Wrong length of a word\n\n");
			printf(DEFAULT);
			continue ;
		}
		if (!is_word(*data->words, temp))
		{
			printf(RED);
			printf(BOLD);
			printf("\n               Not a word\n\n");
			printf(DEFAULT);
			continue ;
		}
		tries++;
		new = newChecker(NULL, NULL, NULL);
		check_word(data->todays_word, temp, new);
		checkerAddBack(data->checker, new);
		head = *data->checker;
		while (i < tries)
		{
			printWord(head);
			head = head->next;
			i++;
		}
		while (i < 6)
		{
			printf("                     _ _ _ _ _  \n\n");	
			i++;
		}
		if (check_word(data->todays_word, temp, new) == CORRECT)
			return (printf(BOLD), printf("                      You win!\n"), printf(DEFAULT), 0);
	}	
	return (printf("\n             No attempts left\n"));
}
