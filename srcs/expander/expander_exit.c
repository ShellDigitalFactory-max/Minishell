/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:04:40 by linux             #+#    #+#             */
/*   Updated: 2025/02/13 02:37:21 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expander_exit(void)
{
	ft_dprintf(STDERR_FILENO, "minishell: memory allocation failure "
		"during expansion. Aborting.\n");
	exit(EXIT_FAILURE);
}
