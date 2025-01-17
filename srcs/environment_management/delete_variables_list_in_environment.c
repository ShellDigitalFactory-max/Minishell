/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_variables_list_in_environment.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:28:01 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/17 16:28:18 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_variables_list_in_environment(t_variable_list *environment)
{
	ft_lstclear(environment, get_environment());
}