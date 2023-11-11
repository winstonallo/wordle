/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getTodaysWord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:31:52 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/11 17:20:43 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"

/**
 * The function calculates a hash value for 
 * a given key using a simple hash algorithm.
 * 
 * @param key The `key` parameter is a pointer to 
 * a character array (string) that represents the key
 * for which we want to calculate the hash value.
 * @param length The "length" parameter represents the 
 * length of the input string "key". It is of type
 * "size_t", which is an unsigned integer type used 
 * for representing sizes and counts.
 * 
 * @return an unsigned integer, which is the calculated 
 * hash value for the given key and length.
 */
unsigned int	hash(const char *key, size_t length)
{
	unsigned int	hash;
	size_t			i;

	hash = 0;
	i = 0;
	while (i < length)
	{
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
		i++;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash);
}

/**
 * The function dailyHash takes a date string in the format 
 * "day month year" and returns a hash value
 * based on the concatenated date.*/
unsigned int	daily_hash(const char *date_string)
{
	char	day[3];
	char	month[4];
	char	year[5];
	char	concatenated_date[12];

	sscanf(date_string, "%s %s %s", day, month, year);
	//get day, month and year from the ctime string
	snprintf(concatenated_date, sizeof(concatenated_date),
		"%s%s%s", year, month, day);
	//concatenate to "yyyymmdd"
	return (hash(concatenated_date, strlen(concatenated_date)));
}

void	get_word(t_data *data, unsigned int hash_value)
{
	t_words	*head;

	head = *data->words;
	while (head)
	{
		if (head->index == hash_value)
		{
			data->todays_word = head->word;
			return ;
		}
		head = head->next;
	}
}

void	get_todays_word(t_data *data)
{
	time_t			timer;
	unsigned int	hash_value;

	time(&timer);
	data->todays_word = ctime(&timer);
	hash_value = daily_hash(data->todays_word) % data->dict_size;
	get_word(data, hash_value);
}
