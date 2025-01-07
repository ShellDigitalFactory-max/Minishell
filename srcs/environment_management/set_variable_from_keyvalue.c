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

int	set_variable_form_keyvalue(t_variable_list variables_list,
		const char *keyvalue, bool make_it_exportable)
{
	
	return (set_variable(variables_list, key, value, make_it_exportable));
}