/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_temp_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:53:00 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/16 16:53:13 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_temp_env_variable(void *node)
{
	char	*variable = (char *)node;

	printf("%s\n", variable);
}

void	print_temp_env(void)
{
	t_temporary_environment	*temp_env;

	temp_env = get_temp_env();
	ft_lstiter(*temp_env, print_temp_env_variable);
}