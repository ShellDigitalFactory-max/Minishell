/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:11:56 by hucherea          #+#    #+#             */
/*   Updated: 2024/12/13 17:56:47 by tchobert         ###   ########.fr       */
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
# include "command_interpretation.h"

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

// DEFINES

# define MSH_LOOP 1

// STRUCTURES

typedef struct s_command_session
{
	char				*user_input_line;
	t_token_list		tokenized_user_input_line;
	t_command_pipeline	command_pipeline;
}				t_command_session;

typedef struct s_minishell_context
{
	t_command_session	command_session;
}				t_minishell_context;

// PROTOTYPES

int					exit_shell_routine(void);
char				*prompt_gets_user_input(void);
t_lexing_status		lexe_input(t_command_session *current_command);
t_syntax_status		parse_input(t_token_list token_list);
t_command_pipeline	semantic_analyzer(t_token_list token_list);

int		command_interpreter(t_minishell_context *minishell_context);
void	execute_command(t_command *command);
char	**list_to_strs_array(t_list *lst, void (conversion_funct)(t_list *, char **));
void	args_list_to_args_array(t_command_args args, char **array);
void	env_list_to_env_array(t_variable_list env, char **array);
t_command_status	build_complete_path(t_command *command, char **command_env);
t_command_status	command_path_manager(
						t_command *command, char **command_env,
						const t_path_type command_path_type);
t_command_status	check_complete_path(t_command *command);

#endif
