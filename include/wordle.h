/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:42:59 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/12 23:19:57 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <time.h>
# include <signal.h>
# include <pthread.h>

# include "macros.h"

typedef struct s_words
{
	char			*word;
	unsigned int	index;
	struct s_words	*next;
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
	pthread_t		monitoring;
	int				exit;
	int				tries;
}	t_data;

int 		main();
int			playGame(t_data *data);
int			printWordle(void);
int			readFile(t_data *data);
int			printWord(t_checker *node);
void		getTodaysWord(t_data *data);
void		freeWords(t_words **wordsList);
void		freeChecker(t_checker **checker);
int			check_word(char *word, char *guess, t_checker *node);
int			is_word(t_words *words, char *str);
void  		ctrlc(int sig);
void		wipe(t_data *data);
void		wordPrinter(t_checker *head, int tries);

#endif