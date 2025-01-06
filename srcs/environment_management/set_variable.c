/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:49:55 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/04 20:50:06 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell_data	minishell_data;

int	set_variable(const char *key, const char *value,
				bool make_it_exportable)
{
	//const t_variable	*variable = get_variable(key);

	// if (variable == NULL)
	// 	update_variable(variable, value, make_it_exportable);
	// else
	add_variable_to_variables_list(key, value,
		make_it_exportable);
		//print error and return si necessaire
	return (EXIT_SUCCESS);
}

// Le reste (update_variable -> modifier une variable qui existe deja)
// est commente  car pour l'instant implementation de l'US ajouter
// une variable a l'env uniquement.