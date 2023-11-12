/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playGame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:46:44 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/12 14:42:11 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int	printWordle(void)
{
	printf(BOLD_CYAN);
	printf("\n                             __   ___\n");
	printf("                            /\\ \\ /\\_ \\\n");
	printf("  __  __  __    ___   _ __  \\_\\ \\\\//\\ \\      __\n");
	printf(" /\\ \\/\\ \\/\\ \\  / __`\\/\\`'__\\/'_` \\ \\ \\ \\   /'__`\\\n");
	printf(" \\ \\ \\_/ \\_/ \\/\\ \\L\\ \\ \\ \\//\\ \\L\\ \\ \\_\\ \\_/\\  __/ \n");
	printf("  \\ \\___x___/'\\ \\____/\\ \\_\\\\ \\___,_\\/\\____\\ \\____\\\n");
	printf("   \\/__//__/   \\/___/  \\/_/ \\/__,_ /\\/____/\\/____/\n");
	printf("                            by abied-ch and jkoupy\n\n");
	printf(DEFAULT);
	printf(BOLD_MAGENTA);
	printf("            Welcome to the game of Worlde.\n");
	printf("     You have 6 guesses to guess the word of today.\n\n");
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

void	freeChecker(t_checker **checker)
{
	t_checker	*head;
	t_checker	*temp;

	if (!checker)
		return ;
	head = *checker;
	while (head)
	{
		temp = head;
		if (head->word)
			free(head->word);
		if (head->color)
			free(head->color);
		if (head->guess)
			free(head->guess);
		head = head->next;
		free(temp);
	}
	free(checker);
}

int	printWord(t_checker *node)
{
	printf("\n                  ");
	for (size_t i = 0; node->guess[i]; i++)
	{
		printf(BOLD);
		if (node->color[i] == 'w')
			printf(GREY);
		if (node->color[i] == 'g')
			printf(GREEN);
		if (node->color[i] == 'y')
			printf(YELLOW);
		printf(" %c ", toupper(node->guess[i]));
		printf(DEFAULT);
	}
	printf("\n");
	return (0);
}
void	printProgress(t_checker *head, int tries)
{
	int	i;

	i = 0;
	wordPrinter(head, tries);
	while (i < 6 - tries)
	{
		printf("\n                   _  _  _  _  _  \n");	
		i++;
	}
	printf("\n");
}

int	youWin(t_checker *head, int tries)
{
	int	i;

	i = 0;
	printProgress(head, tries);
	printf(BOLD);
	printf("\n                🎉🎉 You win! 🎉🎉");
	printf(DEFAULT);
	return (0);
}

void	printAttemptsLeft(int tries)
{
	printf(BOLD);
	printf("                  %d attempts left\n", 6 - tries);
	printf(DEFAULT);
}

int	playGame(t_data *data)
{
	int			tries = 0;
	t_checker	*new;
	t_checker	*head;
	char		temp[8];
	int			first = 1;
	int			error = 0;
	int			result = 0;

	data->checker = malloc(sizeof(t_checker));
	if (!data->checker)
		return (1);
	*data->checker = NULL;
	while (tries < 6)
	{
		system("clear");
		printWordle();
		if (first == 1)
		{
			printf("                  Enjoy the game!\n\n");
			first = 0;
		}
		else if (strlen(temp) != 5)
		{
			printf("               Wrong length of a word\n\n");
			error = 1;
		}
		else if (!is_word(*data->words, temp))
		{
			printf("                     Not a word\n\n");
			error = 1;
		}
		else
		{
			error = 0;
			tries++;
			new = newChecker(NULL, NULL, NULL);
			if (!new)
				return (perror("memory allocation failed"), 1);
			result = check_word(data->todaysWord, temp, new);
			if (result == 1)
				return (1);
			checkerAddBack(data->checker, new);
			head = *data->checker;
			if (result == CORRECT)
				return(youWin(head, tries));
		}
		printAttemptsLeft(tries);
		printProgress(head, tries);
		if (tries != 0 && !error && result == CORRECT)
			return (printf(BOLD), printf("\n               Hope you enjoyed! "), printf(DEFAULT), 0);
		if (tries == 0)
			printf("\n               Guess the word: ");
		else if (tries == 6)
			break ;
		else
			printf("\n                Try again: ");
		if (scanf("%6s", temp) != 1)
			return (1);
	}	
	return (printf(BOLD), printf("\n                    Game Over!\n"), printf(DEFAULT));
}

void wordPrinter(t_checker *head, int tries)
{
	int i = 0;
	while (i < tries)
	{
		printWord(head);
		head = head->next;
		i++;
	}
}
