/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_environment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:39:36 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/07 20:39:48 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_variable_list	get_environment(void)
{
	static t_variable_list	environment = NULL;

	return (&environment);
}