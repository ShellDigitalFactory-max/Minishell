/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:52:23 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/14 19:14:00 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void setUp(void)
{

}
void tearDown(void)
{

}

int	main(void)
{
	UNITY_BEGIN();

	// LEXING

	printf("Testing function: create_token\n\n");
	RUN_TEST(test_create_token);
	printf("\n");
	printf("Testing minishell lexer comportments\n\n");
	RUN_TEST(lexing_bdd_tests);
	printf("\n");

	// PARSING

	printf("Testing minishell parser comportments\n\n");
	RUN_TEST(parsing_bdd_tests);

	// ENVIRONMENT MANAGEMENT

	RUN_TEST(unit_tests_environment_management);

	return (UNITY_END());
}
