/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:11:56 by hucherea          #+#    #+#             */
/*   Updated: 2025/02/13 14:09:36 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// INCLUDES

# include "history.h"
# include "libft.h"
# include "user_interface.h"
# include "lexing.h"
# include "parsing.h"
# include "environment.h"
# include "semantic.h"
# include "expander.h"
# include "command_interpretation.h"

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <limits.h>

// DEFINES

# define MSH_LOOP 1

# define EXIT_STATUS_KEY "?"
# define BUILTIN_ALONE 0
# define BUILTIN_IN_PIPELINE 1
# define PATH_MAX 4096
# define INVALID_ARGUMENT 125
# define COMMAND_NOT_FOUND_EXIT_STATUS 127

// STRUCTURES

typedef struct s_command_session
{
	char				*user_input_line;
	t_token_list		tokenized_user_input_line;
	t_command_pipeline	command_pipeline;
}				t_command_session;

typedef enum e_command_line_analysis_status
{
	INVALID_COMMAND_LINE = -1,
	COMMAND_PIPELINE_SET,
	EMPTY_COMMAND_LINE
}			t_command_line_analysis_status;

typedef struct s_minishell_context
{
	t_command_session	command_session;
}				t_minishell_context;

// ENUMS

typedef enum e_builtin_type
{
	ENV,
	EXPORT,
	PWD,
	CD
}			t_builtin_type;

typedef int	(*t_builtin)(t_command *current_command);

// PROTOTYPES

void				display_minishell_header(void);
int					core_routine(t_minishell_context *minishell_context);
int					exit_shell_routine(void);
char				*prompt_gets_user_input(void);
t_lexing_status		lexe_input(t_command_session *current_command);
t_syntax_status		parse_input(t_token_list token_list);
t_command_pipeline	semantic_analyzer(t_token_list token_list);
bool				is_empty_input(t_token_list tokenized_input);
void				clean_current_loop_context(
						t_minishell_context *minishell_context);

// INTERPRETER

int					command_pipeline_interpreter(
						t_minishell_context *minishell_context);
void				command_process(t_minishell_context *minishell_context,
						t_command *command);
void				clean_command_process(
						t_minishell_context *minishell_context);
t_command_status	execute_command(t_command *command);
char				**list_to_strs_array(t_list *lst,
						void (*conversion_funct)(t_list *, char **));
void				args_list_to_args_array(t_command_args args,
						char **array);
void				env_list_to_env_array(t_variable_list env,
						char **array);
char				**exportable_env_list_to_strs_array(void);
t_command_status	build_complete_path(t_command *command,
						char **command_env);
t_command_status	command_path_manager(
						t_command *command, char **command_env,
						const t_path_type command_path_type);
t_command_status	check_complete_path(t_command *command);
void				add_env_to_env(t_variable_list *dest,
						t_variable_list to_add);
void				add_command_env_to_shell_env(t_variable_list command_env);
void				close_command_process_unused_fds(
						t_minishell_context *minishell_context,
						t_command *command);
int					close_command_pipeline(t_command_pipeline cmd_pipeline,
						pid_t last_command_pid);

// BUILTINS

int					execute_builtin(t_minishell_context *minishell_context,
						t_command *command, bool is_in_pipeline);
int					env(t_command *current_command);
int					export(t_command *command);
void				display_sorted_exportables_variables(char **env);
int					pwd(t_command *command);
char				*get_target_from_args(t_command_args *args);
int					update_env_variables(char *old_pwd);
int					cd(t_command *command);

// EXIT STATUS

void				set_exit_status(int exit_status);
int					get_exit_status_value(void);

#endif
