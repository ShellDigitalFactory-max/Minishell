/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:20:33 by linux             #+#    #+#             */
/*   Updated: 2025/02/15 04:50:12 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_strs(char **strs)
{
	size_t	incre;

	if (strs == NULL)
		return ;
	incre = 0;
	while (strs[incre] != NULL)
	{
		free(strs[incre]);
		++incre;
	}
	free(strs);
}

char	*add_last_arg(char *line, char *arg)
{
	char	*tmp;

	tmp = ft_strjoin(line, arg);
	if (tmp == NULL)
	{
		free(line);
		return (NULL);
	}
	free(line);
	line = tmp;
	return (line);
}
