/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantic.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:51:28 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/13 15:52:02 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEMANTIC_H
# define SEMANTIC_H

// TYPEDEFS

typedef t_list *	t_command_pipeline;
typedef t_list *	t_command;
typedef t_list *	t_temporary_environment;
typedef t_list		t_temporary_variable;

// ENUMS

typedef enum e_assignation_status
{
	VALID_ASSIGNATION,
	INVALID_ASSIGNATION
}				t_assignation_status;

typedef enum e_machine_states
{
	//ERROR = -1,
	SEMANTIC_PROCESS_START,
	ASSIGNATION,
	REDIRECTION,
	COMMAND,
	SEMANTIC_PROCESS_END
}			t_machine_states;

// STRUCTURES

typedef struct s_command_redirections
{
	int	input_redirection;
	int	output_redirection;
}				t_command_redirections;

typedef struct s_command_data
{
	char					*command_name;
	char					**command_and_args;
	char					**command_environment;
	t_command_redirections	command_redirections;
}				t_command_data;

// PROTOTYPES

t_temporary_environment	*get_temporary_environment(void);
void					print_temp_env(void);

t_assignation_status	assignation_checker(char *assignation);
t_machine_states		run_assignation(t_token *current_token);

#endif