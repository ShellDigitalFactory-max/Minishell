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

static void	print_redirection_array(t_command *command)
{
	size_t i = 0;

	while (command->command_redirections.out_stream[i] != NULL)
	{
		printf("redir_array[%zu] = %s\n", i, command->command_redirections.out_stream[i]);
		++i;
	}
}

void	tests_state_output_redirections(void)
{
	printf("\nTesting function \"state_output_redirection\"\n\n");
	// ARRANGE

	t_semantic_analysis_state_return	output;
	t_machine_states					machine_state;
	t_command							command;

	ft_bzero(&command, sizeof(t_command));

	t_token	first_redirection;
	first_redirection.token_lexem = "first_redir";
	first_redirection.token_type = WORD;

	t_token	second_redirection;
	second_redirection.token_lexem = "second_redir";
	second_redirection.token_type = WORD;


	t_token	third_redirection;
	third_redirection.token_lexem = "third_redir";
	third_redirection.token_type = WORD;

	t_token	fourth_redirection;
	fourth_redirection.token_lexem = "fourth_redir";
	fourth_redirection.token_type = WORD;

	// ACT

	output = state_output_redirection(&machine_state, &first_redirection, &command);

	// ASSERT 1

	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, output);
	TEST_ASSERT_EQUAL(0, ft_strcmp(command.command_redirections.out_stream[0], first_redirection.token_lexem));

	// ACT 2

	output = state_output_redirection(&machine_state, &second_redirection, &command);

	// ASSERT 2

	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, output);
	TEST_ASSERT_EQUAL(0, ft_strcmp(command.command_redirections.out_stream[1], second_redirection.token_lexem));

	// ACT 3

	output = state_output_redirection(&machine_state, &third_redirection, &command);

	// ASSERT 3

	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, output);
	TEST_ASSERT_EQUAL(0, ft_strcmp(command.command_redirections.out_stream[2], third_redirection.token_lexem));

	// ACT 4

	output = state_output_redirection(&machine_state, &fourth_redirection, &command);

	// ASSERT 4

	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, output);
	TEST_ASSERT_EQUAL(0, ft_strcmp(command.command_redirections.out_stream[3], fourth_redirection.token_lexem));

	print_redirection_array(&command);

	// CLEAN

	size_t	i = 0;

	while (command.command_redirections.out_stream[i] != NULL)
	{
		free(command.command_redirections.out_stream[i]);
		command.command_redirections.out_stream[i] = NULL;
		++i;
	}
}