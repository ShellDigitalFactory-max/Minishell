/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests_semantic_analyzer.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:44:09 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/13 17:44:18 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	unit_tests_semantic_analyzer(void)
{
	printf("\n\nTesting semantic analyzer functions\n\n");
	tests_assignation_checker();
	tests_state_assignation();
	tests_state_input_redirection();
	tests_state_output_redirections();
	tests_state_append_redirection();
	// tests_multiple_redirections();
	// tests_state_heredoc();
	tests_state_command();
	printf("\n");
}