/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 05:31:01 by linux             #+#    #+#             */
/*   Updated: 2025/02/04 06:23:35 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexem	expand_tilde(size_t *i, t_lexem expanded_word)
{
	t_lexem			tilde_expanded;
	const t_lexem	get_path = get_variable_from_env("HOME");

	tilde_expanded = ft_strjoin(expanded_word, get_path);
	free(expanded_word);
	free(get_path);
	++(*i);
	return (tilde_expanded);
}
