/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_variable_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:55:28 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/09 17:55:38 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_get_variable_value(void)
{
	printf("Testing function \"get_variable_value\"\n\n");

	//ARRANGE

	const char	*variable_keyvalue = "TEST=test";
	const char	*expected_value = "test";
	char	*value;

	// ACT

	value = get_variable_value(variable_keyvalue);

	// ASSERT

	TEST_ASSERT_EQUAL(0, ft_strcmp(value, expected_value));
	printf("Extracted value = %s\n", value);
}