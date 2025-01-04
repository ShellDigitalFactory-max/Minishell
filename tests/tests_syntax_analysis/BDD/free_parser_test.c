/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:28:06 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/30 15:28:19 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_free(void)
{

	printf("Testing parsing with your own input:\n");
	//ARRANGE

	char input[1024];
	printf("Entrez un texte:\n");
	scanf("%[^\n]", input);
	printf("\n");

	t_token_list	token_list = tokenize(input);

	print_token_list(token_list);
	printf("\n");
	printf("TOKEN LIST SIZE: %d\n\n", ft_lstsize(token_list));

	//ACT
	parse_input(token_list);
	//print_token_list(token_list);

	//ASSERT
	//Compare minishell's parser output with bash's parser output, with a similar input.

	//CLEAN
	delete_token_list(token_list);
}
