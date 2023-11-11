/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:42:59 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/11 17:07:41 by jkoupy           ###   ########.fr       */
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
	struct s_words	*next;
}	t_words;

typedef struct s_checker
{
	char	*word;
	char	*guess;
	char	*color;
}	t_checker;

typedef struct s_data
{
	char			*todays_word;
	unsigned int	dict_size;
	t_words			**words;
	t_checker		checker;
}	t_data;

int			main(void);
int			read_file(t_data *data);
int			print_word(t_data *data);
void		get_todays_word(t_data *data);
void		free_words(t_words **words);
int			check_word(char *word, char *guess, t_data *data);
int			is_word(t_words *words, char *str);

#endif