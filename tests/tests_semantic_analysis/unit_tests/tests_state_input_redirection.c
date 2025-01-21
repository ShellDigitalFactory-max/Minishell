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
	token.token_lexem = "infile.txt";
	token.token_type = WORD;

	// ACT

	function_return = state_input_redirection(&machine_state, &token, &command);

	// ASSERT

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_ASSIGNATION, machine_state);
	bytes_read = read(command.command_redirections.in_stream, read_test, 5);
	read_test[bytes_read] = '\0';
	printf("READ = %s\n", read_test);

	//ARRANGE 2

	ft_bzero(&token, sizeof(t_token));
	token.token_lexem = "false_file.txt";
	token.token_type = WORD;
	command.command_name = "ls";

	// ACT 2

	function_return = state_input_redirection(&machine_state, &token, &command);

	// ASSERT 2

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	TEST_ASSERT_EQUAL(-1, command.command_redirections.in_stream);

	//ARRANGE 3

	ft_bzero(&token, sizeof(t_token));
	token.token_lexem = "infile2.txt";
	token.token_type = WORD;
	command.command_name = "ls";

	// ACT 3

	function_return = state_input_redirection(&machine_state, &token, &command);

	// ASSERT 3

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, function_return);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	bytes_read = read(command.command_redirections.in_stream, read_test, 5);
	read_test[bytes_read] = '\0';
	printf("READ = %s\n", read_test);

	// CLEAN

	close(command.command_redirections.in_stream);
}