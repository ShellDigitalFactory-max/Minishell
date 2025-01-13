/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_variable_key.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:16:21 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/09 17:16:27 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_get_variable_key(void)
{
	printf("Testing function \"get_variable_key\"\n\n");

	//ARRANGE

	const char	*variable_keyvalue = "TEST=test";
	const char	*expected_key = "TEST";
	char	*key;

	// ACT

	key = get_variable_key(variable_keyvalue);

	// ASSERT

	TEST_ASSERT_EQUAL(0, ft_strcmp(key, expected_key));
	printf("Extracted key = %s\n\n", key);
	free(key);
}
