/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:26:17 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/09 16:26:28 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_status	update_shell_lvl(t_variable_list *env)
{
	t_variable	*SHLVL;
	unsigned long		shell_level;
	char				*new_shell_level;

	SHLVL = find_variable_in_environment_from_key("SHLVL", env);
	if (SHLVL == NULL)
		return (PROCESS_FAILURE);
	shell_level = ft_atol(SHLVL->value);
	shell_level += 1;
	if (shell_level == 10000)
	{
		shell_level = 1;
		printf("minishell: warning: shell level (10000) too high, "
		"resetting to 1\n");
	}
	new_shell_level = ft_ltoa_base(shell_level, DECIMAL_BASE);
	update_variable(SHLVL, new_shell_level, EXPORTABLE);
	return (PROCESS_SUCCESS);
}

static t_status	update_requested_variables(t_variable_list *env)
{
	return (update_shell_lvl(env));
}

t_status	build_environment(char **variables)
{
	size_t	i;

	i = 0;
	while (variables[i] != NULL)
	{
		if (set_variable_from_keyvalue(variables[i], EXPORTABLE)
			== PROCESS_FAILURE)
			return (PROCESS_FAILURE);
		++i;
	}
	return (update_requested_variables(get_environment()));
}
