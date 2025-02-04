/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:11:56 by hucherea          #+#    #+#             */
/*   Updated: 2025/02/04 06:25:37 by linux            ###   ########.fr       */
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

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>

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

#endif
