/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minishell_header.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:01:55 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/07 15:02:06 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void display_minishell_header(void)
{
	const char *RED_BRIGHT = "\x1b[91m";
	const char *RESET = "\x1b[0m";

	printf("%s", RED_BRIGHT);
	printf("\n");
	printf("----------------------------------------\n");
	printf("  ___  ____       _     _          _ _   \n");
	printf(" |  \\/  (_)     (_)   | |        | | |  \n");
	printf(" | .  . |_ _ __  _ ___| |__   ___| | |  \n");
	printf(" | |\\/| | | '_ \\| / __| '_ \\ / _ \\ | |  \n");
	printf(" | |  | | | | | | \\__ \\ | | |  __/ | |  \n");
	printf(" \\_|  |_/_|_| |_|_|___/_| |_|\\___|_|_|  \n");
	printf("                                        \n");
	printf("-----Alloue plus vite que la CAF.-------\n\n");
	printf("%s", RESET);
}
