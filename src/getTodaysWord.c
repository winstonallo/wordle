/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getTodaysWord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:31:52 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/12 14:22:17 by abied-ch         ###   ########.fr       */
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
static unsigned int	hash(const char *key, size_t length)
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
static unsigned int	dailyHash(const char *dateString)
{
	char	day[3];
	char	month[4];
	char	year[5];
	char	concatenatedDate[12];

	sscanf(dateString, "%s %s %s", day, month, year);
	//get day, month and year from the ctime string
	snprintf(concatenatedDate, sizeof(concatenatedDate),
		"%s%s%s", year, month, day);
	//concatenate to "yyyymmdd"
	return (hash(concatenatedDate, strlen(concatenatedDate)));
}

static void	getWord(t_data *data, unsigned int hashValue)
{
	t_words	*head;

	head = *data->words;
	while (head)
	{
		if (head->index == hashValue)
		{
			data->todaysWord = head->word;
			return ;
		}
		head = head->next;
	}
}

void	getTodaysWord(t_data *data)
{
	time_t			timer;
	unsigned int	hashValue;

	time(&timer);
	data->todaysWord = ctime(&timer);
	hashValue = dailyHash(data->todaysWord) % data->dictSize;
	getWord(data, hashValue);
}
