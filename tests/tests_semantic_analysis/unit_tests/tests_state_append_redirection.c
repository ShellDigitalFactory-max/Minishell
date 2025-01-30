/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_state_append_redirection.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:55:56 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/22 15:56:13 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_state_append_redirection(void)
{
	printf("\nTesting function \"state_append_redirection\"\n\n");
	// ARRANGE

	t_semantic_analysis_state_return	function_return;
	t_machine_states					machine_state;
	t_token								token;
	t_command							command;
	char								*write_for_test = "Hello test append";

	ft_bzero(&command, sizeof(t_command));
	token.token_lexem = "./files_for_testing_redirections/outfile_for_append.txt";
	token.token_type = WORD;

	// ACT

	function_return = state_append_redirection(&machine_state, &token, &command);

	//ASSERT

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	write(command.command_redirections.out_stream, write_for_test, ft_strlen(write_for_test));

	// // ARRANGE 2

	// ft_bzero(&token, sizeof(t_token));
	// token.token_lexem = "./files_for_testing_redirections/outfile_to_create_append.txt";
	// token.token_type = WORD;

	// // ACT 2

	// function_return = state_append_redirection(&machine_state, &token, &command);

	// //ASSERT 2

	// TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	// TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	// write(command.command_redirections.out_stream, write_for_test, ft_strlen(write_for_test));

	// // ARRANGE 3

	// ft_bzero(&token, sizeof(t_token));
	// token.token_lexem = "./files_for_testing_redirections/outfile_no_rights.txt";
	// token.token_type = WORD;
	// const char	*expected_error_msg = "minishell: permission denied: ./files_for_testing_redirections/outfile_no_rights.txt";

	// // ACT 3

	// function_return = state_output_redirection(&machine_state, &token, &command);

	// //ASSERT 3

	// TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	// TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	// TEST_ASSERT_EQUAL(OPENING_ERROR, command.command_redirections.out_stream);
	// TEST_ASSERT_EQUAL(OPENING_FAILURE, command.command_redirections.opening_status);
	// TEST_ASSERT_EQUAL(0, ft_strcmp(expected_error_msg, command.opening_failure_msg));
}