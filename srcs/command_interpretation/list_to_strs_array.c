/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:25:17 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/31 16:25:35 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**list_to_strs_array(t_list *lst,
				void (*conversion_funct)(t_list *, char **))
{
	const size_t	array_size = ft_lstsize(lst);
	char			**array;

	array = (char **)malloc(sizeof(char *) * (array_size + 1));
	if (array != NULL)
	{
		array[array_size] = NULL;
		conversion_funct(lst, array);
	}
	return (array);
}
