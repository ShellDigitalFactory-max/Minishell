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

	t_variable_list	variables_list = NULL;

	const char	*key = "KEY";
	const char	*value = "VALUE";

	//ACT

	variables_list = add_variable_to_variables_list(variables_list, key, value, true);

	//ASSERT

	TEST_ASSERT_EQUAL(0, ft_strncmp(((t_variable *)variables_list->content)->key, key, ft_strlen(key)));
	TEST_ASSERT_EQUAL(0, ft_strncmp(((t_variable *)variables_list->content)->value, value, ft_strlen(value)));
	TEST_ASSERT_EQUAL(true, ((t_variable *)variables_list->content)->is_exportable);

	printf("Variable_list first node key = %s\n", ((t_variable *)variables_list->content)->key);
	printf("Variable list first node value = %s\n", ((t_variable *)variables_list->content)->key);

	//CLEAN

	delete_variables_list(variables_list);
	printf("\n");
}