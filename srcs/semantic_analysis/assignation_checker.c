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
	char	*probable_key;
	size_t	i;

	if (is_assignation(assignation) == false || ft_isdigit(*assignation)
			== true)
		return (INVALID_ASSIGNATION);
	probable_key = get_variable_key(assignation);
	i = 0;
	while (probable_key[i] != '\0')
	{
		if (ft_isalnum(probable_key[i]) == false)
			return (INVALID_ASSIGNATION);
		++i;
	}
	return (VALID_ASSIGNATION);
}
