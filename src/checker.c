/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:06:57 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/12 10:53:11 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"

int	check_correct(t_checker *a)
{
	int	i;
	int	correct;

	i = 0;
	correct = 0;
	while (i < 5)
	{
		if (a->word[i] == a->guess[i])
		{
			a->color[i] = 'g';
			correct++;
		}
		i++;
	}
	return (correct == 5);
}

void	check_misplaced(t_checker *a)
{
	int	i; //word
	int	j; //guess

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			if (a->color[j] == 'g' || a->color[j] == 'y')
			{
				j++;
				continue ;
			}
			if (a->word[i] == a->guess[j] && a->color[i] != 'g')
			{
				a->color[j] = 'y';
				break ;
			}
			j++;
		}
		i++;
	}
}

int	check_word(char *word, char *guess, t_checker *node)
{
	node->color = NULL;
	node->word = NULL;
	node->guess = NULL;
	node->color = strdup("wwwwww");
	if (!node->color)
		return (1);
	node->guess = strdup(guess);
	if (!node->guess)
		return (1);
	node->word = strdup(word);
	if (!node->word)
		return (1);
	if (check_correct(node))
		return (CORRECT);
	check_misplaced(node);
	if (check_correct(node)) //can it be correct here?
		return (CORRECT);
	return (0);
}
