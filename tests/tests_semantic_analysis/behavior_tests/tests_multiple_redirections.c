/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_multiple_redirections.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:51:44 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/22 16:51:59 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_multiple_redirections(void)
{
	printf("\nTesting multiple redirection in one input\n\n");

	// IMPORTANT : BEFORE ANY TEST, EXECUTE THE BASH SCRIPT "RESTART_FILES" LOCATED IN DIRECTORY "files_for_testing_multiples_redirections" AT THE ROOT OF THE PROJECT !!!

	// A few simple tests
	// See in directory "files_for_testing_multiples_redirections" at the root of the project for checking the results of those tests.

	/// CASE ONE :

	// Testing input like :		"> file1 >> file2 > file3"
	//---> file 1, file2 and file3 aren't empty. The content of file2 should not be erased, the one of file1 and 3 should be erased.


	// ARRANGE -> file1

	t_semantic_analysis_state_return	function_return;
	t_machine_states					machine_state;
	t_token								token;
	t_command							command;

	ft_bzero(&command, sizeof(t_command));
	token.token_lexem = "./files_for_testing_multiples_redirections/file1";

	// ACT

	function_return = state_output_redirection(&machine_state, &token, &command);

	// ASSERT

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);

	//ARRANGE -> file2

	ft_bzero(&token, sizeof(token));
	token.token_lexem = "./files_for_testing_multiples_redirections/file2";
	token.token_type = WORD;

	// ACT

	function_return = state_append_redirection(&machine_state, &token, &command);

	// ASSERT

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);

	// ARRANGE -> file3

	ft_bzero(&token, sizeof(token));
	token.token_lexem = "./files_for_testing_multiples_redirections/file3";
	token.token_type = WORD;

	// ACT

	function_return = state_output_redirection(&machine_state, &token, &command);

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);

	// CLEAN

	close(command.command_redirections.out_stream);


////////////////////////////////////////////////////////////////////////////////////////////


/// CASE ONE :

	// Testing input like :		"> file4 >> file5 > file6" ---> IMPORTANT = NO RIGHTS ON FILE5 !!!!

	//---> file 4, file5 and file6 aren't empty. The content of file4 should be erased. The process should stop by trying to open file5
	// then the contents of file 4 and 5 should not be erased. An error message should be display.

// ARRANGE -> file4

	ft_bzero(&command, sizeof(t_command));
	token.token_lexem = "./files_for_testing_multiples_redirections/file4";

	// ACT

	function_return = state_output_redirection(&machine_state, &token, &command);

	// ASSERT

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);

	//ARRANGE -> file5

	ft_bzero(&token, sizeof(token));
	token.token_lexem = "./files_for_testing_multiples_redirections/file5";
	token.token_type = WORD;

	// ACT

	function_return = state_append_redirection(&machine_state, &token, &command);

	// ASSERT

	TEST_ASSERT_EQUAL(OPENING_ERROR, command.command_redirections.out_stream);
	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);

	// ARRANGE -> file6

	ft_bzero(&token, sizeof(token));
	token.token_lexem = "./files_for_testing_multiples_redirections/file6";
	token.token_type = WORD;

	// ACT

	function_return = state_output_redirection(&machine_state, &token, &command);

	TEST_ASSERT_EQUAL(OPENING_ERROR, command.command_redirections.out_stream);
	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
}