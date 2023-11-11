/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:42:59 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/11 21:26:41 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <time.h>

# include "macros.h"

typedef struct s_words
{
	char			*word;
	unsigned int	index;
	struct s_words 	*next;
}	t_words;


typedef struct s_checker
{
	char				*word;
	char				*guess;
	char				*color;
	struct s_checker	*next;
}	t_checker;

typedef struct s_data
{
	char			*todaysWord;
	unsigned int	dictSize;
	t_words			**words;
	t_checker		**checker;
	char			**guesses;
}	t_data;

int 		main();
int			playGame(t_data *data);
int			readFile(t_data *data);
int			printWord(t_checker *node);
void		getTodaysWord(t_data *data);
void		freeWords(t_words **words);
int			check_word(char *word, char *guess, t_checker *node);
int			is_word(t_words *words, char *str);

#endif