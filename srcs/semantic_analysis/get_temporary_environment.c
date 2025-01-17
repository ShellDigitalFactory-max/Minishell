/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_temporary_environment.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:56:42 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/17 12:56:58 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_variable_list	*get_temporary_environment(void)
{
	static t_variable_list	temporary_environment = NULL;

	return (&temporary_environment);
}