/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:10:49 by hucherea          #+#    #+#             */
/*   Updated: 2024/12/12 14:31:09 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INTERFACE_H
# define USER_INTERFACE_H

// INCLUDES

# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "libft.h"

// DEFINES

# define MSH_PROMPT "SDF$> "
# define HEREDOC_PROMPT "captain'hirdock>"
# define CTRL_D 0
# define FAILURE -1
# define MAIN_PROMPT 0
# define SUBPROMPT 1

// PROTOTYPES

void	signal_handler(int signum);
void	received_signal(void);
char	*prompt_gets_user_input(bool is_subprompt);
void	setup_signals(struct sigaction *sa);

#endif
