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

t_status	set_variable_from_keyvalue(const char *keyvalue,
			bool make_it_exportable)
{
	return (set_variable_from_keyvalue_to_environment(keyvalue,
				make_it_exportable, get_environment()));
}
