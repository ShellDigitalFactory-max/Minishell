/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variable_from_keyvalue.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:14:42 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/07 19:14:53 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_status set_variable_from_keyvalue(t_variable_list variables_list,
// 		const char *keyvalue, bool make_it_exportable)
// {
// 	char	*key;
// 	char	*value;

// 	key = get_variable_key(keyvalue);
// 	if (key == NULL)
// 		return (PROCESS_FAILURE);
// 	value = get_variable_value(keyvalue);
// 	if (value == NULL)
// 	{
// 		free(key);
// 		return (PROCESS_FAILURE);
// 	}
// 	return (PROCESS_SUCCESS);
// 	//verifier si le nom de la variable est correct
// 	return (set_variable(key, value, make_it_exportable));
// }