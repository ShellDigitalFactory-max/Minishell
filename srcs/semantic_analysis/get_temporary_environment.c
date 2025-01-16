/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_temporary_environment.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:56:47 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/16 13:56:59 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_temporary_environment	*get_temp_env(void)
{
	static t_temporary_environment	temp_env = NULL;

	return (&temp_env);
}