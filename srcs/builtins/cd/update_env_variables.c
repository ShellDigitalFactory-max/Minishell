/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 04:02:58 by linux             #+#    #+#             */
/*   Updated: 2025/02/13 04:30:30 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_env_variables(char *old_pwd)
{
	char	new_pwd[PATH_MAX];

	if (set_variable_to_environment("OLDPWD", old_pwd, EXPORTABLE,
			get_environment()))
	{
		perror("set_variable_to_environment OLD_PWD");
		return (EXIT_FAILURE);
	}
	if (getcwd(new_pwd, PATH_MAX) == NULL)
	{
		perror("getcwd");
		return (EXIT_FAILURE);
	}
	if (set_variable_to_environment("PWD", new_pwd, EXPORTABLE,
			get_environment()))
	{
		perror("set_variable_to_environment PWD");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
