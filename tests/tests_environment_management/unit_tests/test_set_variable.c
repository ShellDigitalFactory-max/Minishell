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

void	test_set_variable(void)
{
	// ARRANGE

	char	*key = "VAR_NAME";
	char	*value = "test";

	// ACT

	t_variable	*variable = set_variable(key, value, EXPORTABLE | SET);

	//ASSERT

	TEST_ASSERT_EQUAL(0, ft_strncmp(key, variable->key, ft_strlen(key)));
	TEST_ASSERT_EQUAL(0, ft_strncmp(key, variable->value, ft_strlen(value)));
	TEST_ASSERT_EQUAL(EXPORTABLE | SET, variable->state);
}