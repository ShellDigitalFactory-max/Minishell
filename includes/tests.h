/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:46:44 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/14 19:15:01 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

// INCLUDES

# include "unity.h"
# include "libft.h"
# include "minishell.h"

/// PROTOTYPES ///

// LEXING

void	lexing_bdd_tests(void);
void	test_input_just_a_space(void);
void	test_input_just_one_pipe(void);
void	test_input_pipe_and_input_redir(void);
void	test_input_pipe_and_redirs(void);
void	test_input_operators_and_one_char(void);
void	test_input_heredoc(void);
void	test_input_just_one_word(void);
void	test_input_two_words(void);
void	test_input_word_with_double_quotes(void);
void	test_input_word_with_simple_quotes(void);

void	test_create_token(void);

// PARSING

void	parsing_bdd_tests(void);
void	test_input_empty_string(void);
void	test_input_just_a_pipe(void);
void	test_input_two_pipes(void);
void	test_free(void);

// ENVIRONMENT MANAGEMENT

void	unit_tests_environment_management(void);
void	test_create_variable(void);

#endif