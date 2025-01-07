/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_variable_from_keyvalue.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:04:22 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/07 19:04:36 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_set_variable_from_keyvalue(void)
{
	//ARRANGE

	const char		*keyvalue = "test=variable";
	const char		*expected_key = "test";
	const char		*expected_value = "variable";
	t_variable_list	variables_list = NULL;

	//ACT

	set_variable_from_keyvalue(variables_list, keyvalue);

	//ASSERT

	TEST_ASSERT_EQUAL(0, ft_strncmp(((t_variable *)variables_list->content)->key, expected_key, ft_strlen(expected_key)));
	TEST_ASSERT_EQUAL(0, ft_strncmp(((t_variable *)variables_list->content)->value, expected_value, ft_strlen(expected_value)));
}