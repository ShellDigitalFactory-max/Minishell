/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:34:01 by linux             #+#    #+#             */
/*   Updated: 2025/02/17 13:27:59 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*add_args(char *line, char *arg)
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
	tmp = ft_strjoin(line, " ");
	free(line);
	line = tmp;
	return (line);
}

static char	*add_new_line(char *line, t_new_line_status new_line_status)
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
	return (line);
}

static char	*make_line_from_args(char **args, size_t i,
		t_new_line_status new_line_status)
{
	char	*line;

	line = ft_strdup("");
	if (line == NULL)
		return (NULL);
	while (args[i] != NULL)
	{
		if (args[i + 1] == NULL)
			line = add_last_arg(line, args[i]);
		else
			line = add_args(line, args[i]);
		++i;
	}
	if (new_line_status == NEW_LINE)
	{
		line = add_new_line(line, new_line_status);
	}
	return (line);
}

static t_new_line_status	is_new_line_option(char **args, size_t *i)
{
	t_new_line_status	new_line_status;

	new_line_status = NEW_LINE;
	while (args[*i] != NULL && ft_strncmp(args[*i], "-n", 2) == 0)
	{
		++*i;
		new_line_status = NO_NEW_LINE;
	}
	return (new_line_status);
}

int	echo(t_command *command)
{
	t_new_line_status	new_line_status;
	char				**args;
	char				*line_printed;
	size_t				i;

	i = 1;
	new_line_status = NEW_LINE;
	args = list_to_strs_array(command->command_args, args_list_to_args_array);
	if (args == NULL)
		return (EXIT_FAILURE);
	new_line_status = is_new_line_option(args, &i);
	line_printed = make_line_from_args(args, i, new_line_status);
	if (line_printed == NULL)
	{
		free_strs(args);
		return (EXIT_FAILURE);
	}
	ft_putstr_fd(line_printed, STDOUT_FILENO);
	free_strs(args);
	free(line_printed);
	return (EXIT_SUCCESS);
}
