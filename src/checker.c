/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:06:57 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/11 12:51:20 by jkoupy           ###   ########.fr       */
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

t_checker	check_word(char *word, char *guess)
{
	t_checker	a;

	a.color = malloc(6);
	a.guess = malloc(6);
	a.word = malloc(6);
	strcpy(a.color, "wwwww");
	strcpy(a.word, word);
	strcpy(a.guess, guess);
	if (check_correct(&a))
		return (a);
	check_misplaced(&a);
	return (a);
}