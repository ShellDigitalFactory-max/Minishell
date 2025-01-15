/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:54:09 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/15 18:14:47 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

// INCLUDES

# include "minishell.h"

// DEFINES

# define EQUAL_OPERATOR '='
# define EXPORTABLE 1

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
	bool	is_exportable;
}				t_variable;

// PROTOTYPES

t_variable_list	*get_environment(void);
t_status		build_environment(char **variables);
t_status		set_variable_from_keyvalue(const char *keyvalue,
					bool make_it_exportable);
t_status		set_variable(const char *key, const char *value,
					bool make_it_exportable);
t_variable		*create_variable(const char *key, const char *value,
					bool is_exportable);
t_status		update_variable(t_variable *variable, const char *value,
					const bool is_exportable);
t_variable		*find_variable_from_key(const t_variable_list *environment,
					char *key);
bool			is_variable_key_equal(void *variable_as_content, void *key);
t_status		add_variable_to_environment(t_variable_list *environment,
					t_variable *variable);
void			delete_variable(void *data);
void			delete_variables_list(void);
char			*get_variable_key(const char *keyvalue);
char			*get_variable_value(const char *keyvalue);
void			print_env(void);

#endif
