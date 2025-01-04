/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:54:09 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/04 18:58:35 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

// INCLUDES

# include "minishell.h"

// TYPEDEFS

typedef char * t_string;

// ENUMS

typedef enum e_state
{
	NO_STATE = 0x00,
	SET = 0x01,
	EXPORTABLE = 0x02,
	READONLY = 0x04
}			t_state;

// STRUCTURES

typedef struct s_variable
{
	t_string	key;
	t_string	value;
	t_state		state;
}				t_variable;

// PROTOTYPES



#endif