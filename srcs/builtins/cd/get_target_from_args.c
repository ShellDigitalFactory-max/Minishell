/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_from_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:31:10 by linux             #+#    #+#             */
/*   Updated: 2025/02/13 04:05:29 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	*get_target_with_no_arg(void)
{
	char	*target;

	target = get_variable_from_env("HOME");
	if (target == NULL)
	{
		fprintf(stderr, "minishell: cd: HOME not set\n");
		return (NULL);
	}
	return (target);
}

static	char	*get_target_with_args(char *current_arg)
{
	char	*target;

	target = ft_strdup(current_arg);
	if (target == NULL)
	{
		fprintf(stderr, "cd: OLDPWD not set\n");
		return (NULL);
	}
	return (target);
}

char	*get_target_from_args(char	**args)
{
	char	*current_arg;
	char	*target;

	current_arg = args[1];
	if (current_arg == NULL)
	{
		target = get_target_with_no_arg();
	}
	else
	{
		target = get_target_with_args(current_arg);
	}
	return (target);
}
