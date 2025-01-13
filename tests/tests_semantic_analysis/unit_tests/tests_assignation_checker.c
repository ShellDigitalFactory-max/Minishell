/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_assignation_checker.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:27:52 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/13 17:28:04 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_assignation_checker(void)
{
	printf("\nTesting function \"assignation_checker\"\n");
	// ARRANGE

	char	*assignation_1 = "Hello=Bonjour";
	char	*assignation_2 = "VAR=2";
	char	*assignation_3 = "V=2";
	char	*assignation_4 = "VARIABLE=";
	char	*assignation_5 = "=variable";
	char	*assignation_6 = "=";
	char	*assignation_7 = "";
	char	*assignation_8 = "2VAR=test";
	char	*assignation_9 = "VA*R=test";
	char	*assignation_10 = "VA!!R=test";
	char	*assignation_11 = "VAR=tes****t";

	// ACT

	t_assignation_status	assign_1 = assignation_checker(assignation_1);
	t_assignation_status	assign_2 = assignation_checker(assignation_2);
	t_assignation_status	assign_3 = assignation_checker(assignation_3);
	t_assignation_status	assign_4 = assignation_checker(assignation_4);
	t_assignation_status	assign_5 = assignation_checker(assignation_5);
	t_assignation_status	assign_6 = assignation_checker(assignation_6);
	t_assignation_status	assign_7 = assignation_checker(assignation_7);

	t_assignation_status	assign_8 = assignation_checker(assignation_8);
	t_assignation_status	assign_9 = assignation_checker(assignation_9);
	t_assignation_status	assign_10 = assignation_checker(assignation_10);
	t_assignation_status	assign_11 = assignation_checker(assignation_11);

	// ASSERT

	TEST_ASSERT_EQUAL(VALID_ASSIGNATION, assign_1);
	TEST_ASSERT_EQUAL(VALID_ASSIGNATION, assign_2);
	TEST_ASSERT_EQUAL(VALID_ASSIGNATION, assign_3);
	TEST_ASSERT_EQUAL(VALID_ASSIGNATION, assign_4);
	TEST_ASSERT_EQUAL(INVALID_ASSIGNATION, assign_5);
	TEST_ASSERT_EQUAL(INVALID_ASSIGNATION, assign_6);
	TEST_ASSERT_EQUAL(INVALID_ASSIGNATION, assign_7);
	TEST_ASSERT_EQUAL(INVALID_ASSIGNATION, assign_8);
	TEST_ASSERT_EQUAL(INVALID_ASSIGNATION, assign_9);
	TEST_ASSERT_EQUAL(INVALID_ASSIGNATION, assign_10);
	TEST_ASSERT_EQUAL(VALID_ASSIGNATION, assign_11);
}