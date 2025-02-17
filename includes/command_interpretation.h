/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_interpretation.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:42:46 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/30 20:42:50 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_INTERPRETATION_H
# define COMMAND_INTERPRETATION_H

// INCLUDES

# include "minishell.h"

// DEFINES

# define RELATIVE_PREFIX '.'
# define ABSOLUTE_PREFIX "/"

// ENUMS

typedef enum e_path_type
{
	RELATIVE_PATH,
	COMPLETE_ABSOLUTE_PATH,
	UNCOMPLETE_ABSOLUTE_PATH
}				t_path_type;

typedef enum e_command_status
{
	ERROR_SYSTEM,
	ERROR_DENIED,
	ERROR_NOT_FOUND,
	ERROR_COMMAND = -1,
	INVALID_COMMAND = -1,
	VALID_COMMAND
}				t_command_status;

typedef t_command_status	(*t_path_manager_func)(t_command *command,
													char **command_environment);

// PROTOTYPES

#endif