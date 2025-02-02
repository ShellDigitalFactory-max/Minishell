/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests_state_input_redirection.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:58:56 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/20 17:59:08 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_state_input_redirection(void)
{
	printf("\nTesting function \"state_input_redirection\"\n\n");
	// ARRANGE

	t_semantic_analysis_state_return	function_return;
	t_machine_states					machine_state;
	t_token								token;
	t_command							command;
	ssize_t								bytes_read;
	char								read_test[10];

	ft_bzero(&command, sizeof(t_command));
	token.token_lexem = "./files_for_testing_redirections/infile.txt";
	token.token_type = WORD;

	// ACT

	function_return = state_input_redirection(&machine_state, &token, &command);

	// ASSERT

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_ASSIGNATION, machine_state);
	bytes_read = read(command.command_redirections.in_stream, read_test, 5);
	read_test[bytes_read] = '\0';
	printf("READ = %s", read_test);
	printf("BYTES_READ = %zu\n", bytes_read);

	//ARRANGE 2

	ft_bzero(&token, sizeof(t_token));
	token.token_lexem = "./files_for_testing_redirections/false_file.txt";
	token.token_type = WORD;

	// ACT 2

	function_return = state_input_redirection(&machine_state, &token, &command);

	// ASSERT 2

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_ASSIGNATION, machine_state);
	TEST_ASSERT_EQUAL(OPENING_ERROR, command.command_redirections.in_stream);
	TEST_ASSERT_EQUAL(OPENING_FAILURE, command.command_redirections.opening_status);
	printf("%s\n\n", command.opening_failure_msg);
}