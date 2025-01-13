/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantic.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:51:28 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/13 15:52:02 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEMANTIC_H
# define SEMANTIC_H

// ENUMS

typedef enum e_assignation_status
{
	VALID_ASSIGNATION,
	INVALID_ASSIGNATION
}				t_assignation_status;

// PROTOTYPES

t_assignation_status	assignation_checker(char *assignation);

#endif