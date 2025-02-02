/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command_pipeline_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:21:12 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/24 16:21:24 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_command_pipeline_list(t_command_pipeline	cmd_pipeline)
{
	ft_lstiter(cmd_pipeline, print_command);
}