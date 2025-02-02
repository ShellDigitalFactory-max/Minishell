/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_state_assignation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:03:40 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/20 14:03:50 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_state_assignation(void)
{
	printf("\nTesting function \"state_assignation\"\n\n");
	// ARRANGE

	t_machine_states					machine_state;
	t_semantic_analysis_state_return	expected_return;
	t_command							command;
	t_token								token;
	token.token_lexem = "VAR=test";
	token.token_type = WORD;
	ft_bzero(&command, sizeof(t_command));
	char								*expected_key = "VAR";
	char								*expected_value = "test";

	// ACT

	expected_return = state_assignation(&machine_state, &token, &command);

	// ASSERT

	TEST_ASSERT_EQUAL(machine_state, STATE_ASSIGNATION);
	TEST_ASSERT_EQUAL(expected_return, TOKEN_PROCESSED);
	TEST_ASSERT_EQUAL(0, ft_strcmp(expected_key, ((t_variable *)command.command_environment->content)->key));
	TEST_ASSERT_EQUAL(0, ft_strcmp(expected_value, ((t_variable *)command.command_environment->content)->value));
	printf("Command environment =\n");
	print_env(&command.command_environment);

	// CLEAR

	delete_variables_list_in_environment(&command.command_environment);
	ft_bzero(&command, sizeof(t_command));
	ft_bzero(&token, sizeof(t_token));

	// ARRANGE 2

	token.token_lexem = "THIS IS NOT A VARIABLE";
	token.token_type = WORD;

	// ACT 2

	expected_return = state_assignation(&machine_state, &token, &command);

	// ASSERT 2

	TEST_ASSERT_EQUAL(machine_state, STATE_COMMAND);
	TEST_ASSERT_EQUAL(expected_return, TOKEN_NOT_PROCESSED);
	TEST_ASSERT_EQUAL(NULL, (command.command_environment));

	// CLEAR 2

	ft_bzero(&command, sizeof(t_command));
	ft_bzero(&token, sizeof(t_token));
}