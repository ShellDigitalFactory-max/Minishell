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

void	test_add_variable_to_environment(void)
{
	printf("Testing function \"add_variable_to_variable_list\"\n\n");

	//ARRANGE

	char	*key = "KEY";
	char	*value = "VALUE";
	char	*key_2 = "KEY_2";
	char	*value_2 = "VALUE_2";
	t_variable_list	variables_list = NULL;

	t_variable	variable = {.key = "KEY", .value = "VALUE", .is_exportable = true};
	t_variable	variable_2 = {.key = "KEY_2", .value = "VALUE_2", .is_exportable = false};

	//ACT

	add_variable_to_environment(&variables_list, &variable);
	add_variable_to_environment(&variables_list, &variable_2);

	//ASSERT

	TEST_ASSERT_EQUAL(0, ft_strcmp(((t_variable *)variables_list->content)->key, key));
	TEST_ASSERT_EQUAL(0, ft_strcmp(((t_variable *)variables_list->content)->value, value));
	TEST_ASSERT_EQUAL(true, ((t_variable *)variables_list->content)->is_exportable);

	printf("Variable_list first node key = %s\n", ((t_variable *)variables_list->content)->key);
	printf("Variable list first node value = %s\n\n", ((t_variable *)variables_list->content)->value);

	t_variable_list	second_node = (t_variable_list)variables_list->next;

	TEST_ASSERT_EQUAL(0, ft_strcmp(((t_variable *)second_node->content)->key, key_2));
	TEST_ASSERT_EQUAL(0, ft_strcmp(((t_variable *)second_node->content)->value, value_2));
	TEST_ASSERT_EQUAL(false, ((t_variable *)second_node->content)->is_exportable);

	printf("Variable_list second node key = %s\n", ((t_variable *)second_node->content)->key);
	printf("Variable list second node value = %s\n\n", ((t_variable *)second_node->content)->value);

	printf("Testing function \"find_variable_from_key\"\n\n");

	t_variable	*search_result;

	search_result = find_variable_from_key(&variables_list, key_2);

	TEST_ASSERT_EQUAL(0, ft_strcmp(search_result->key, key_2));
	printf("Result found key = %s\n", search_result->key);

	//CLEAN

	free(variables_list);
	free(second_node);
	//delete_variables_list_tests_version(&variables_list);
	printf("\n");
}