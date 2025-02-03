/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:45:28 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/03 15:45:51 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_empty_input(t_token_list tokenized_input)
{
	const size_t	list_size = ft_lstsize(tokenized_input);

	if (list_size > 2)
		return (false);
	if (((t_token *)tokenized_input->content)->token_type == TOKEN_LIST_START
		&& list_size == 2)
		return (true);
	return (false);
}