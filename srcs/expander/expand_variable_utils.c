/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 05:04:51 by linux             #+#    #+#             */
/*   Updated: 2025/02/15 05:05:24 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*manage_return_cmd(t_lexem temp_expanded, t_lexem expanded_word)
{
	char	*return_cmd;

	return_cmd = ft_itoa(get_exit_status_value());
	expanded_word = ft_strjoin(temp_expanded, return_cmd);
	free(temp_expanded);
	free(return_cmd);
	return (expanded_word);
}
