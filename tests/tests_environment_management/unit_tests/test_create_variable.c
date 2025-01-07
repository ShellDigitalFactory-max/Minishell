/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:38:36 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/04 19:38:45 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_create_variable(void)
{
	// ARRANGE

	const char	*key = "VAR_NAME";
	const char	*value = "test";
	const char	*key_2 = "NAME_VAR";
	const char	*value_2 = "";

	// ACT

	t_variable	*variable = create_variable(key, value, true);
	t_variable	*variable_2 = create_variable(key_2, value_2, false);

	// ASSERT

	TEST_ASSERT_EQUAL(0, ft_strncmp(key, variable->key, ft_strlen(key)));
	printf("Variable key = %s\n", variable->key);
	TEST_ASSERT_EQUAL(0, ft_strncmp(value, variable->value, ft_strlen(value)));
	printf("Variable value = %s\n", variable->value);
	TEST_ASSERT_EQUAL(true, variable->is_exportable);

	TEST_ASSERT_EQUAL(0,ft_strncmp(key_2, variable_2->key, ft_strlen(key_2)));
	printf("Variable 2 key = %s\n", variable_2->key);
	TEST_ASSERT_EQUAL(0, *variable_2->value);
	printf("Variable 2 value = %s\n", variable_2->value);
	TEST_ASSERT_EQUAL(false, variable_2->is_exportable);

	// CLEAN

	delete_variable(variable);
	delete_variable(variable_2);
}