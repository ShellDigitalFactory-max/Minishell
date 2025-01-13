/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:57:07 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/14 18:41:10 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

// INCLUDES

# include "minishell.h"

// ENUMS

typedef enum e_syntax_status
{
	PARSING_IN_PROGRESS,
	VALID_SYNTAX,
	INVALID_SYNTAX
}			t_syntax_status;

#endif
