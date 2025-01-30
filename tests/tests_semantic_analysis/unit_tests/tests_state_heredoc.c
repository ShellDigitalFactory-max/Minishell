/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_state_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:57:43 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/22 18:57:53 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_state_heredoc(void)
{
	printf("\nTesting function \"state_heredoc\" : A HEREDOC WITH THE WORD \"test\" AS A DELIMITER !!!\n\n");
	// ARRANGE

	t_command							command;
	t_machine_states					machine_state;
	t_semantic_analysis_state_return	output;
	t_token								token;

	ft_bzero(&command, sizeof(t_command));
	command.command_name = "ls";
	token.token_lexem = "test";
	token.token_type = WORD;

	// ACT

	output = state_heredoc(&machine_state, &token, &command);

	// ASSERT

	TEST_ASSERT_EQUAL(TOKEN_PROCESSED, output);
	TEST_ASSERT_EQUAL(STATE_ASSIGNATION, machine_state);
}