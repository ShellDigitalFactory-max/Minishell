/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:23:45 by linux             #+#    #+#             */
/*   Updated: 2025/02/13 18:38:51 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_quote(char c, t_quote_state quote_state)
{
	if (quote_state == NO_QUOTE && (c == '\'' || c == '\"'))
		return (true);
	else if (quote_state == SINGLE_QUOTE && c == '\'')
		return (true);
	else if (quote_state == DOUBLE_QUOTE && c == '\"')
		return (true);
	else
		return (false);
}

void	change_quote_state(char quote, t_quote_state *quote_state)
{
	if (*quote_state == NO_QUOTE && quote == '\'')
	{
		*quote_state = SINGLE_QUOTE;
	}
	else if (*quote_state == NO_QUOTE && quote == '\"')
		*quote_state = DOUBLE_QUOTE;
	else if (*quote_state == SINGLE_QUOTE && quote == '\'')
		*quote_state = NO_QUOTE;
	else if (*quote_state == DOUBLE_QUOTE && quote == '\"')
		*quote_state = NO_QUOTE;
}
