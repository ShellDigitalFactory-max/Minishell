/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_variable_in_environment_from_key.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:34:13 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/17 16:34:25 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_variable	*find_variable_in_environment_from_key(char *key,
				const t_variable_list *environment)
{
	return (ft_list_find_first_content_match((t_variable_list)(*environment),
				key, is_variable_key_equal));
}