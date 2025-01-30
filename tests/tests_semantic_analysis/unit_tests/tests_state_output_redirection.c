/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_state_output_redirection.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:55:38 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/21 11:55:49 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_state_output_redirections(void)
{
	printf("\nTesting function \"state_output_redirection\"\n\n");
	// ARRANGE

	t_semantic_analysis_state_return	function_return;
	t_machine_states					machine_state;
	t_token								token;
	t_command							command;
	char								*write_for_test = "Hello test";

	ft_bzero(&command, sizeof(t_command));
	token.token_lexem = "./files_for_testing_redirections/outfile.txt";
	token.token_type = WORD;

	// ACT

	function_return = state_output_redirection(&machine_state, &token, &command);

	//ASSERT

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	write(command.command_redirections.out_stream, write_for_test, ft_strlen(write_for_test));

	// ARRANGE 2

	ft_bzero(&token, sizeof(t_token));
	token.token_lexem = "./files_for_testing_redirections/outfile_to_create.txt";
	token.token_type = WORD;
	command.command_name = "ls";

	// ACT 2

	function_return = state_output_redirection(&machine_state, &token, &command);

	//ASSERT 2

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	write(command.command_redirections.out_stream, write_for_test, ft_strlen(write_for_test));

	// ARRANGE 3

	ft_bzero(&token, sizeof(t_token));
	token.token_lexem = "./files_for_testing_redirections/outfile_no_rights.txt";
	token.token_type = WORD;

	// ACT 3

	function_return = state_output_redirection(&machine_state, &token, &command);

	//ASSERT 3

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	TEST_ASSERT_EQUAL(OPENING_ERROR, command.command_redirections.out_stream);
	TEST_ASSERT_EQUAL(OPENING_FAILURE, command.command_redirections.opening_status);
	printf("\n%s\n\n", command.opening_failure_msg);
}
