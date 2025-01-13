/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_variables_list_tests_version.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:09:27 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/08 19:09:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	delete_variables_list_tests_version(t_variable_list *variable_list)
{
	ft_lstclear(variable_list, delete_variable);
}