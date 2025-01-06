/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:54:09 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/04 18:58:35 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

// INCLUDES

# include "minishell.h"

// TYPEDEFS

typedef t_list *	t_variable_list;
typedef char *		t_string;

// ENUMS

// STRUCTURES

typedef struct s_variable
{
	t_string	key;
	t_string	value;
	bool		is_exportable;
}				t_variable;

// PROTOTYPES

int			set_variable(const char *key, const char *value,
				bool make_it_exportable);
t_variable	*create_variable(const char *key, const char *value,
						bool is_exportable);
void		delete_variable(void *data);

// QUAND COPIE ENV VERIFIER SI VALEUR EST NULLE OU EXPORTABLE

#endif