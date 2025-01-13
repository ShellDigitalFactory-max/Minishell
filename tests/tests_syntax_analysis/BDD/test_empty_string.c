/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_empty_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:13:43 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/29 14:13:56 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_input_empty_string(void)
{
	printf("Testing parsing: empty string\n");
	//ARRANGE

	t_syntax_status	parser_output;
	t_token_list	token_list = tokenize("");

	print_token_list(token_list);

	//ACT
	parser_output = parse_input(token_list);
	//print_token_list(token_list);

	//ASSERT
	TEST_ASSERT_EQUAL(VALID_SYNTAX, parser_output);

	//CLEAN
	delete_token_list(token_list);
}
