/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:06:57 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/11 13:58:34 by abied-ch         ###   ########.fr       */
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
	int	i;
	int	j;

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
			if (a->word[i] == a->guess[j])
			{
				a->color[j] = 'y';
				break ;
			}
			j++;
		}
		i++;
	}
}

int	check_word(char *word, char *guess, t_data *data)
{
	data->checker.color = NULL;
	data->checker.word = NULL;
	data->checker.guess = NULL;
	data->checker.color = strdup("wwwwww");
	if (!data->checker.color)
		return (1);
	data->checker.guess = strdup(guess);
	if (!data->checker.guess)
		return (1);
	data->checker.word = strdup(word);
	if (!data->checker.word)
		return (1);
	if (check_correct(&data->checker))
		return (CORRECT);
	check_misplaced(&data->checker);
	return (0);
}
