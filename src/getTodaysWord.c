/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getTodaysWord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:31:52 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/11 12:55:23 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"

unsigned int hash(const char *key, size_t length)
{
    unsigned int hash = 0;
    size_t i;

    for (i = 0; i < length; ++i) {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

unsigned int dailyHash(const char *dateString) 
{
    char day[3], month[4], year[5];
    sscanf(dateString, "%s %s %s", day, month, year);
    char concatenatedDate[12];
    snprintf(concatenatedDate, sizeof(concatenatedDate), "%s%s%s", year, month, day);
    return (hash(concatenatedDate, strlen(concatenatedDate)));
}

void	getWord(t_data *data, unsigned int hashValue)
{
	t_words *head;

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
	time_t	timer;
	
	time(&timer);
	data->todaysWord = ctime(&timer);
	unsigned int hashValue = dailyHash(data->todaysWord) % data->dictSize;
	getWord(data, hashValue);
    printf("Hash value for \"%s\": %u\n", data->todaysWord, hashValue);
	printf("%s", data->todaysWord);
}
