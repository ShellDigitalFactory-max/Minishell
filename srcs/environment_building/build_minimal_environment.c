/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_minimal_environment.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:58:08 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/15 18:58:17 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	set_pwd(void)
{
	char	*pwd_variable;
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		perror("getcwd");
		return (PROCESS_FAILURE);
	}
	if (ft_asprintf(&pwd_variable, "PWD=%s", cwd) == -1)
		return (PROCESS_FAILURE);
	if (set_variable_from_keyvalue(pwd_variable, EXPORTABLE) == PROCESS_FAILURE)
		return (PROCESS_FAILURE);
	return (PROCESS_SUCCESS);
}

t_status	build_minimal_environment(void)
{
	if (set_variable_from_keyvalue("SHLVL=1", EXPORTABLE) == PROCESS_FAILURE)
		return (PROCESS_FAILURE);
	return (set_pwd());
}
