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

// ENUMS

typedef enum e_status
{
	PROCESS_SUCCESS,
	PROCESS_FAILURE
}			t_status;

// STRUCTURES

typedef struct s_variable
{
	char	*key;
	char	*value;
	bool		is_exportable;
}				t_variable;

// PROTOTYPES

t_variable_list	*get_environment(void);
int				set_variable(const char *key, const char *value,
					bool make_it_exportable);
t_variable		*create_variable(const char *key, const char *value,
					bool is_exportable);
t_status		update_variable(t_variable *variable, const char* value,
					const bool is_exportable);
t_variable		*find_variable_from_key(const t_variable_list *environment,
					const char *key);
bool			is_variable_key_equal(void *variable_as_content, void *key);
t_status		add_variable_to_environment(const t_variable_list *environment,
				t_variable *variable);
void			delete_variable(void *data);
void			delete_variables_list(void);

// QUAND COPIE ENV VERIFIER SI VALEUR EST NULLE OU EXPORTABLE

#endif