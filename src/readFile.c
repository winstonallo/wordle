/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readFile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:30:13 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/11 12:06:22 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"

static t_words	*newWord(char *name)
{
	t_words	*new;

	if (!name)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->word = name;
	new->next = NULL;
	return (new);
}

static void	wordAddBack(t_words **lst, t_words *new_node)
{
	t_words	*current;

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

void	printWords(t_words **wordsList)
{
	t_words	*head;

	head = *wordsList;
	while (head)
	{
		for (int i = 0; head->word[i]; i++)
			printf("%c", head->word[i]);
		head = head->next;
	}
}

static void	freeWords(t_words **wordsList)
{
	t_words	*head;
	t_words	*temp;

	head = *wordsList;
	while (head)
	{
		temp = head;
		free(head->word);
		head = head->next;
		free(temp);
	}
	free(wordsList);
}

int	readFile(t_data *data)
{
	t_words	*new;
	char	buffer[10000];
	char	*temp;
	FILE 	*file = fopen("words.txt", "r");
	if (!file)
		return (perror("Error opening file"), 1);
	data->words = malloc(sizeof(t_words));
	if (!data->words)
		return (fclose(file), 1);
	*data->words = NULL;
	while (fgets(buffer, sizeof(buffer), file))
	{
		temp = strndup(buffer, 6);
		if (!temp)
			return (free(temp), freeWords(data->words), fclose(file), 1);
		new = newWord(temp);
		if (!new)
			return (free(temp), freeWords(data->words), fclose(file), 1);
		wordAddBack(data->words, new);
	}
	freeWords(data->words);
	if (fclose(file) < 0)
		return (fclose(file));
	return (0);
}