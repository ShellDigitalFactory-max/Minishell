/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:36:34 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/09 19:36:49 by tchobert         ###   ########.fr       */
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

void	print_env(t_variable_list *env)
{
	ft_lstiter(*env, print_variable);
}