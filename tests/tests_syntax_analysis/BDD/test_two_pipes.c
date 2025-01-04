/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_two_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:40:46 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/29 14:41:00 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_input_two_pipes(void)
{
	printf("Testing parsing: two pipes\n");
	//ARRANGE

	t_syntax_status	parser_output;
	t_token_list	token_list = tokenize("<<");

	print_token_list(token_list);

	//ACT
	parser_output = parse_input(token_list);
	//print_token_list(token_list);

	//ASSERT
	TEST_ASSERT_EQUAL(INVALID_SYNTAX, parser_output);

	//CLEAN
	delete_token_list(token_list);
}
