/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:38:24 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/06 16:38:33 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	export_variables(char **variables)
{
	size_t	i;

	i = 0;
	while (variables[i] != NULL)
	{
		if (assignation_checker(variables[i]) == INVALID_ASSIGNATION)
		{
			ft_dprintf(STDERR_FILENO, "minishell: export: "
				"`%s': not a valid identifier\n", variables[i]);
		}
		else
			set_variable_from_keyvalue(variables[i], EXPORTABLE);
		++i;
	}
	return (EXIT_SUCCESS);
}

int	export(t_command *command)
{
	char	**variables_to_export;

	variables_to_export = NULL;
	if (ft_lstsize(command->command_args) == 1)
	{
		display_sorted_exportables_variables(
			exportable_env_list_to_strs_array());
		return (EXIT_SUCCESS);
	}
	variables_to_export = list_to_strs_array(command->command_args,
			args_list_to_args_array);
	export_variables(variables_to_export + 1);
	ft_free_and_null(variables_to_export);
	return (EXIT_SUCCESS);
}
