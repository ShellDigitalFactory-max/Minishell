/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:34:01 by linux             #+#    #+#             */
/*   Updated: 2025/02/14 23:05:27 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_args(char *line, char *arg)
{
	char	*tmp;

	tmp = ft_strjoin(line, arg);
	if (tmp == NULL)
	{
		free(line);
		return ;
	}
	free(line);
	line = tmp;
	tmp = ft_strjoin(line, " ");
	free(line);
	line = tmp;
}

static void	add_new_line(char *line, t_new_line_status new_line_status)
{
	char	*tmp;

	if (new_line_status == NEW_LINE)
	{
		tmp = ft_strjoin(line, "\n");
		if (tmp == NULL)
		{
			free(line);
			return (NULL);
		}
		free(line);
		line = tmp;
	}
	free(line);
	return ;
}

static char	*make_line_from_args(char **args, int *i,
		t_new_line_status new_line_status)
{
	char	*line;
	char	*tmp;

	line = ft_strdup("");
	if (line == NULL)
		return (NULL);
	while (args[*i] != NULL)
	{
		add_args(line, args[*i]);
	}
	if (new_line_status == NEW_LINE)
	{
		add_new_line(line, new_line_status);
	}
	return (line);
}

static bool	is_new_line_option(char **args, int *i)
{
	if (ft_strncmp(args[*i], "-n", 2) == 0)
	{
		++*i;
		return (NO_NEW_LINE);
	}
	return (NEW_LINE);
}

int	echo(t_command *command)
{
	t_new_line_status	new_line_status;
	char				**args;
	char				*line_printed;

	new_line_status = NEW_LINE;
	args = list_to_strs_array(command->command_args, args_list_to_args_array);
	if (args == NULL)
		return (EXIT_FAILURE);
	new_line_status = is_new_line_option(args, &i);
	line_printed = make_line_from_args(args, i, new_line_status);
	free_strs_array(args);
	if (line_printed == NULL)
		return (EXIT_FAILURE);
	ft_putstr_fd(line_printed, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
