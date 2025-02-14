/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_delimiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:57:18 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/14 19:57:30 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_delimiter(const char *delimiter, const char *line)
{
	const size_t	delimiter_size = ft_strlen(delimiter);
	const size_t	line_size = ft_strlen(line);

	return (delimiter_size == line_size && ft_strcmp(line, delimiter) == 0);
}