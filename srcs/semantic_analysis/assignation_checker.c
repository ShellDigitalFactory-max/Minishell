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

static bool	is_first_letter_valid(const char c)
{
	return (ft_isalpha(c) || c == '_');
}

bool	is_assignation(const char *assignation)
{
	const char	*is_equal_operator = ft_strchr(assignation, EQUAL_OPERATOR);

	return (is_equal_operator != NULL && is_equal_operator != assignation);
}

t_assignation_status	assignation_checker(char *assignation)
{
	char	*probable_key;
	size_t	i;

	if (is_assignation(assignation) == false
		|| is_first_letter_valid(*assignation) == false)
		return (INVALID_ASSIGNATION);
	probable_key = get_variable_key(assignation);
	if (probable_key == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc failure. Aborting.\n");
		exit(FAILURE);
	}
	i = 1;
	while (probable_key[i] != '\0')
	{
		if (ft_isalnum(probable_key[i]) == false && probable_key[i] != '_')
		{
			free(probable_key);
			return (INVALID_ASSIGNATION);
		}
		++i;
	}
	free(probable_key);
	return (VALID_ASSIGNATION);
}
