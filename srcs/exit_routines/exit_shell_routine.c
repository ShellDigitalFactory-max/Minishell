/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:01:58 by hucherea          #+#    #+#             */
/*   Updated: 2024/12/11 13:56:45 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_shell_routine(void)
{
	const int	exit_value = get_exit_status_value();

	delete_variables_list();
	ft_putstr_fd("exit\n", STDERR_FILENO);
	exit(exit_value);
}
