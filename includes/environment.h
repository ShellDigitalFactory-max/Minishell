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

// STRUCTURES

typedef struct s_variable
{
	t_string	key;
	t_string	value;
	bool		is_exportable;
}				t_variable;

// PROTOTYPES

// QUAND COPIE ENV VERIFIER SI VALEUR EST NULLE OU EXPORTABLE

#endif