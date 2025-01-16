/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_temp_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:26:42 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/16 14:26:54 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	delete_temporary_node(void *data)
{
	char	*to_clear;

	to_clear = (char *)data;
	//free(to_clear);
	to_clear = NULL;
}

void	clear_temp_env(void)
{
	t_temporary_environment	*temp_env;

	temp_env = get_temp_env();
	ft_lstclear(temp_env, delete_temporary_node);
}