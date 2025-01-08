/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:02:18 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/07 18:02:33 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_add_variable_to_variables_list(void)
{
	printf("Testing function \"add_variable_to_variable_list\"\n");
	
	//ARRANGE

	const char	*key = "KEY";
	const char	*value = "VALUE";
	t_variable_list	*variables_list = NULL;

	t_variable	variable = {.key = "KEY", .value = "VALUE", .is_exportable = true};

	//ACT

	add_variable_to_environment(variables_list, &variable);

	//ASSERT

	TEST_ASSERT_EQUAL(0, ft_strcmp(((t_variable *)(*variables_list)->content)->key, key));
	TEST_ASSERT_EQUAL(0, ft_strcmp(((t_variable *)(*variables_list)->content)->value, value));
	TEST_ASSERT_EQUAL(true, ((t_variable *)(*variables_list)->content)->is_exportable);

	printf("Variable_list first node key = %s\n", ((t_variable *)(*variables_list)->content)->key);
	printf("Variable list first node value = %s\n", ((t_variable *)(*variables_list)->content)->key);

	//CLEAN

	delete_variables_list_tests_version(variables_list);
	printf("\n");
}