/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:42:59 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/11 14:14:16 by abied-ch         ###   ########.fr       */
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
	char	*word;
	char	*guess;
	char	*color;
}	t_checker;

typedef struct s_data
{
	char			*todaysWord;
	unsigned int	dictSize;
	t_words			**words;
	t_checker		checker;
}	t_data;

int			main();
int			readFile(t_data *data);
int			printWord(t_data *data);
void		getTodaysWord(t_data *data);
void		freeWords(t_words **words);
int			check_word(char *word, char *guess, t_data *data);
int			is_word(t_words *words, char *str);

#endif