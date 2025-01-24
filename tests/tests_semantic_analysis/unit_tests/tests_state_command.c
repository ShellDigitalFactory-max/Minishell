/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_state_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:25:38 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/23 18:25:48 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	print_arguments_list(t_command_args arguments_list)
{
	ft_lstiter(arguments_list, print_argument);
}

void	tests_state_command(void)
{
	printf("\nTesting function \"state_command\"\n\n");
	// ARRANGE

	t_semantic_analysis_state_return	output;
	t_token								token;
	t_command							command;
	t_machine_states					machine_state;

	ft_bzero(&command, sizeof(t_command));
	token.token_lexem = "test";
	token.token_type = INPUT_REDIR_OPERATOR;

	// ACT

	output = state_command(&machine_state, &token, &command);

	// ASSERT

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, output);
	TEST_ASSERT_EQUAL(STATE_INPUT_REDIRECT, machine_state);

	// ARRANGE 2

	ft_bzero(&token, sizeof(t_token));
	token.token_lexem = "ls";
	token.token_type = WORD;

	// ACT 2

	output = state_command(&machine_state, &token, &command);

	// ASSERT 2

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, output);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	print_arguments_list(command.command_args);
	printf("ARGUMENTS_LIST SIZE = %d\n", ft_lstsize(command.command_args));
	printf("\n");

	// ARRANGE 3

	ft_bzero(&token, sizeof(t_token));
	token.token_lexem = "-l -a -test test test";
	token.token_type = WORD;

	// ACT 3

	output = state_command(&machine_state, &token, &command);

	// ASSERT 3

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, output);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	print_arguments_list(command.command_args);
	printf("ARGUMENTS_LIST SIZE = %d\n", ft_lstsize(command.command_args));
	printf("\n");

	// ARRANGE 4

	ft_bzero(&token, sizeof(t_token));
	token.token_lexem = "";
	token.token_type = WORD;

	// ACT 4

	output = state_command(&machine_state, &token, &command);

	// ASSERT 4

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, output);
	TEST_ASSERT_EQUAL(STATE_COMMAND, machine_state);
	print_arguments_list(command.command_args);
	printf("ARGUMENTS_LIST SIZE = %d\n", ft_lstsize(command.command_args));
	printf("\n");
}