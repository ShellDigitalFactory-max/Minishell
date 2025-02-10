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

# define OPENING_ERROR -1
# define HEREDOC_PROCESSING 1

// TYPEDEFS

typedef t_list *							t_command_pipeline;
typedef t_list *							t_command_args;
typedef int									t_stream;
typedef char *								t_command_argument;

// ENUMS

typedef enum s_semantic_analysis_state_return
{
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

typedef enum e_opening_status
{
	OPENING_FAILURE = -1,
	OPENING_SUCCESS,
}			t_opening_status;

typedef enum e_command_nature
{
	NO_ENTRY,
	UNDEFINED,
	ONLY_ASSIGNATION,
	POSSIBLE_BINARY,
	BUILTIN
}			t_command_nature;

// STRUCTURES

typedef struct s_command_redirections
{
	t_opening_status	opening_status;
	t_stream			in_stream;
	t_stream			out_stream;
}				t_command_redirections;

typedef struct s_command
{
	char					*command_name;
	char					*command_binary_path;
	t_command_args			command_args;
	t_variable_list			command_environment;
	t_command_redirections	command_redirections;
	t_command_nature		command_nature;
	char					*opening_failure_msg;
	pid_t					command_pid;
}				t_command;

typedef struct s_semantic_machine
{
	t_machine_states	machine_state;
	t_stream			next_command_input;
}				t_semantic_machine;

typedef t_semantic_analysis_state_return	(*t_semantic_state_function)(
			t_semantic_machine *semantic_machine, t_token *current_token,
			t_command *current_command);

// PROTOTYPES

void								save_opening_error(
										t_command *current_command,
										const char *file_name);
t_command							*create_command(
										t_semantic_machine *machine);
t_assignation_status				assignation_checker(char *assignation);
t_semantic_analysis_state_return	state_assignation(
										t_semantic_machine *semantic_machine,
										t_token *current_token,
										t_command *current_command);
t_semantic_analysis_state_return	state_input_redirection(
										t_semantic_machine *semantic_machine,
										t_token *current_token,
										t_command *current_command);
t_semantic_analysis_state_return	state_output_redirection(
										t_semantic_machine *semantic_machine,
										t_token *current_token,
										t_command *current_command);
t_semantic_analysis_state_return	state_append_redirection(
										t_semantic_machine *semantic_machine,
										t_token *current_token,
										t_command *current_command);
t_semantic_analysis_state_return	state_heredoc(
										t_semantic_machine *semantic_machine,
										t_token *current_token,
										t_command *current_command);
t_semantic_analysis_state_return	state_command(
										t_semantic_machine *semantic_machine,
										t_token *current_token,
										t_command *current_command);
t_semantic_analysis_state_return	state_end_of_command(
										t_semantic_machine *semantic_machine,
										t_command_pipeline *cmd_pipeline,
										t_command *current_command,
										t_token *current_token);
void								setup_pipe(
										t_semantic_machine *semantic_machine,
										t_command *command);
void								delete_command_pipeline(
										t_command_pipeline *cmd_pipeline);
void								get_command_name(t_command *command);
bool								is_builtin(const char *command_name);

void								print_arguments_list(
										t_command_args arguments_list);
void								print_argument(void *to_print);
void								print_command_pipeline_list(
										t_command_pipeline	cmd_pipeline);
void								print_command(void *to_print);

#endif