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

// DEFINES

# define MAX_REDIRECTIONS 100
# define OPENING_ERROR -1

// TYPEDEFS

typedef t_list *	t_command_pipeline;
typedef t_list		t_command_args;
typedef int			t_stream;
typedef char *		command_argument;

// ENUMS

typedef enum s_semantic_analysis_state_return
{
	OPENING_FAILURE = -1,
	TOKEN_NOT_PROCESSED,
	TOKEN_PROCESSED,
	END_OF_TOKEN_LIST
}				t_semantic_analysis_state_return;

typedef enum e_assignation_status
{
	VALID_ASSIGNATION,
	INVALID_ASSIGNATION
}				t_assignation_status;

typedef enum e_machine_states
{
	STATE_OPENING_FAILURE = -1,
	STATE_ASSIGNATION,
	STATE_INPUT_REDIRECT,
	STATE_OUTPUT_REDIRECT,
	STATE_APPEND_REDIRECT,
	STATE_HEREDOC,
	STATE_COMMAND,
	STATE_NEW_COMMAND,
	STATE_END_OF_COMMAND,
	SEMANTIC_PROCESS_START,
	SEMANTIC_PROCESS_END
}			t_machine_states;

// STRUCTURES

typedef struct	s_token_type_and_machine_state
{
	t_token_type 		token_type;
	t_machine_states	machine_state;
}				t_token_type_and_machine_state;

typedef struct s_command_redirections
{
	t_stream	in_stream;
	t_stream	out_stream;
}				t_command_redirections;

typedef struct s_command
{
	char					*command_name;
	char					**args;
	t_variable_list			command_environment;
	t_command_redirections	command_redirections;
}				t_command;

typedef t_semantic_analysis_state_return (*t_semantic_state_function)(
			t_machine_states *machine_state, t_token *current_token);

// PROTOTYPES

void								display_opening_errors(const char *file_name);
t_assignation_status				assignation_checker(char *assignation);
t_semantic_analysis_state_return	state_assignation(
										t_machine_states *machine_state,
										t_token *current_token,
										t_command *current_command);
t_semantic_analysis_state_return	state_input_redirection(
										t_machine_states *machine_state,
										t_token *current_token,
										t_command *current_command);
t_semantic_analysis_state_return	state_output_redirection(
										t_machine_states *machine_state,
										t_token *current_token,
										t_command *current_command);
t_semantic_analysis_state_return	state_append_redirection(
										t_machine_states *machine_state,
										t_token *current_token,
										t_command *current_command);
t_semantic_analysis_state_return	state_heredoc(
										t_machine_states *machine_state,
										t_token *current_token,
										t_command *current_command);
t_semantic_analysis_state_return	state_command(
										t_machine_states *machine_state,
										t_token *current_token,
										t_command *current_command);
t_semantic_analysis_state_return	state_end_of_command(t_machine_states *machine_state,
										t_command_pipeline *cmd_pipeline, 
										t_command *current_command,
										t_token *current_token);

#endif