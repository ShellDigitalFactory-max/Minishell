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

	ft_bzero(&command, sizeof(t_command));
	token.token_lexem = "infile.txt";
	token.token_type = WORD;

	// ACT

	function_return = state_input_redirection(&machine_state, &token, &command);

	// ASSERT

	TEST_ASSERT_EQUAL(machine_state, STATE_ASSIGNATION);
	TEST_ASSERT_EQUAL(0, ft_strcmp(token.token_lexem, command.command_redirections.in_stream));
	TEST_ASSERT_EQUAL(function_return, TOKEN_PROCESSED);

	printf("\nINPUT_REDIR = %s\n", command.command_redirections.in_stream);

	// ARRANGE 2

	ft_bzero(&token, sizeof(t_token));
	token.token_lexem = "infile_n2.txt";
	token.token_type = WORD;

	// ACT 2

	function_return = state_input_redirection(&machine_state, &token, &command);

	// ASSERT 2

	TEST_ASSERT_EQUAL(machine_state, STATE_ASSIGNATION);
	TEST_ASSERT_EQUAL(0, ft_strcmp(token.token_lexem, command.command_redirections.in_stream));
	TEST_ASSERT_EQUAL(function_return, TOKEN_PROCESSED);

	printf("\nINPUT_REDIR = %s\n", command.command_redirections.in_stream);

	// CLEAN

	free(command.command_redirections.in_stream);
}