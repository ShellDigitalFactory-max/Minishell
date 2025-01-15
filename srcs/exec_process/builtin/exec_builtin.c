/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:43:08 by linux             #+#    #+#             */
/*   Updated: 2025/01/15 18:15:56 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_status	exec_builtin(t_lexem	cmd_builtin)
{
	if (ft_strcmp(cmd_builtin, "env") == 0)
		env_builtin(get_environment());
	return (PROCESS_SUCCESS);
}
