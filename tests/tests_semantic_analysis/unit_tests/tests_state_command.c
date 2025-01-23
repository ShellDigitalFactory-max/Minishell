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

void	tests_state_command(void)
{
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
}