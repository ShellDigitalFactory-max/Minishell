/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:06:34 by linux             #+#    #+#             */
/*   Updated: 2025/01/15 18:11:48 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static void	print_variable(void *content)
{
	const t_variable	*variable = (t_variable *)content;

	printf("%s", variable->key);
	printf("=");
	printf("%s\n", variable->value);
}

void	env_builtin(t_variable_list	*env) // tellement plus propre cette version ;)
{
	ft_lstiter(*env, &print_variable);
}
