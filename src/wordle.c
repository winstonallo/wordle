/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:42:44 by abied-ch          #+#    #+#             */
/*   Updated: 2023/11/11 10:54:50 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wordle.h"

int main() {
    // ANSI escape code to set background color to green
    printf(GREEN);
    printf("Green Background");
    printf(DEFAULT);

    // ANSI escape code to set background color to grey
    printf(GREY);
    printf("Grey Background");
    printf(DEFAULT);


    // ANSI escape code to set background color to yellow
    printf(YELLOW);
    printf("Yellow Background");

    // Reset ANSI escape codes to default (resets both foreground and background colors)
    printf(DEFAULT);

    return 0;
}
