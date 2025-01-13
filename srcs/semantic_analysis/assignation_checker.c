/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignation_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:08:35 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/13 18:08:40 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_assignation(const char *assignation)
{
	const char	*is_equal_operator = ft_strchr(assignation, EQUAL_OPERATOR);

	return (is_equal_operator != NULL && is_equal_operator != assignation);
}

t_assignation_status	assignation_checker(char *assignation)
{
	if (is_assignation(assignation) == false)
		return (INVALID_ASSIGNATION);
	return (VALID_ASSIGNATION);
}
