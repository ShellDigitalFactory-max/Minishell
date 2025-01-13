/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests_environment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:58:30 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/04 19:58:40 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	unit_tests_environment_management(void)
{
	printf("\nTesting environment management -> unit tests\n\n");
	test_create_variable();
	test_add_variable_to_environment();
	test_get_variable_key();
	test_get_variable_value();
	printf("\n");
}