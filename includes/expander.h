/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:34:13 by linux             #+#    #+#             */
/*   Updated: 2025/02/05 15:13:25 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


typedef enum	e_quote_state
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
} t_quote_state;

t_lexem	expand_tilde(size_t *i, t_lexem expanded_word);
t_lexem	get_variable_from_env(const char *key);
void expand_input(t_token_list token_list);
t_lexem	expand_tilde(size_t *i, t_lexem expanded_word);
t_lexem	expand_word(t_lexem word);
t_lexem	no_expand(t_lexem word, size_t *i, t_lexem expanded_word);
t_lexem	expand_variable(t_lexem word, size_t *i, t_lexem expanded_word);
