/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command_env_to_shell_env.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:36:52 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/30 20:37:03 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_command_env_to_shell_env(t_variable_list command_env)
{
	add_env_to_env(get_environment(), command_env);
}
