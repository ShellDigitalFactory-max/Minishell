/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:06:34 by linux             #+#    #+#             */
/*   Updated: 2025/01/16 12:12:13 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_variable(void *content)
{
	const t_variable	*variable = (t_variable *)content;

	if (variable->is_exportable == true)
	{
		printf("%s", variable->key);
		printf("=");
		printf("%s\n", variable->value);
	}
}

void	env_builtin(t_variable_list	*env)
{
	ft_lstiter(*env, &print_variable);
}
