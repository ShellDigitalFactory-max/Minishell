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

# include <stdio.h>
# include <stdlib.h>

// DEFINES

# define MSH_LOOP 1

// STRUCTURES

typedef struct s_command_session
{
	char			*user_input_line;
	t_token_list	tokenized_user_input_line;
}				t_command_session;

typedef struct s_minishell_context
{
	t_command_session	command_session;
	t_variable_list		variables_list;
}				t_minishell_context;

// PROTOTYPES

int				exit_shell_routine(void);
char			*prompt_gets_user_input(void);
t_lexing_status	lexe_input(t_command_session *current_command);
t_syntax_status	parse_input(t_token_list token_list);

#endif
