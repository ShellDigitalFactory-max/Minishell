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
	int fd;

	fd = open("./files_for_testing_redirections/outfile_no_rights.txt", O_RDONLY);
	if (fd > 0)
	{
		close (fd);
		printf("\n\nBEFORE ANY TEST PLEASE RUN THE SCRIPT \"setup_files.sh\", LOCATED IN \"./files_for_testing_redirections\".\n\nDON'T FORGET TO RUN THE SCRIPT \"rest_files.sh\" ONCE ALL TEST ARE DONE.\n\n");
		return (EXIT_FAILURE);
	}

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

	// SEMANTIC ANALYSIS

	RUN_TEST(unit_tests_semantic_analyzer);

	return (UNITY_END());
}
