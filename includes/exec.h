/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:50:23 by linux             #+#    #+#             */
/*   Updated: 2025/01/16 12:14:58 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

char		**make_builtin_tab(void);
bool		is_builtin_command(char *command);
t_status	exec_builtin(t_lexem	cmd_builtin);
void		env_builtin(t_variable_list	*env);

#endif
