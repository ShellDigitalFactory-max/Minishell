/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_simple_command_valid.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:45:54 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/14 19:11:58 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_input_just_a_pipe(void)
{
	printf("Testing parsing: just a pipe\n");
	//ARRANGE

	t_syntax_status	parser_output;
	t_token_list	token_list = tokenize("|");

	print_token_list(token_list);

	//ACT
	parser_output = parse_input(token_list);
	//print_token_list(token_list);

	//ASSERT
	TEST_ASSERT_EQUAL(INVALID_SYNTAX, parser_output);

	//CLEAN
	delete_token_list(token_list);
}

/*

IMPORTANT:

-> Ici l'idee c'est de tester comment le parser reagit a differentes suites de
   tokens ! Pour voir si il identifie bien les suites logiques et valides,
   ou illogiques et invalides entre les tokens qu'on lui presente.

   Pour savoir si un token est correctement forme, et savoir si les donnees qu'il
   contient sont correctement remplies, et correspondent bien a son type, son
   contenu, etc ... il faut se referer aux tests unitaires qui seront effectues
   sur le module de lexing.


---------------------------------------------------------------------------------

MODULE PARSING =

1/ Le lexer :

INPUT = une chaine de caracteres (constante ?), l'input de l'utilisateur.
OUTPUT = une liste ordonnee de tokens --> (dans le but de la fournir au PARSER)

GOAL = decouper la ligne de commande entree par l'utilisateur en une suite de lexem
		(suite d'entites comprises dans le lexique du shell)

PROCESS =


2/ L'analyseur de syntaxe :

INPUT = une suite de lexems (voir structure de donnees, surement une liste chainee)
OUTPUT = une enum indiquant si cette suite de lexems respecte la syntaxe du shell

GOAL = definir si la suite de tokens qui lui est fourni respecte la syntaxe du shell

PROCESS =


cw -Iincludes -IUnity/src -Ilibft/includes tests/tests_main.c tests/feature_syntax_analysis/parsing/parsing_bdd.c tests/feature_syntax_analysis/parsing/test_simple_command_valid.c srcs/syntax_analysis/parsing/syntax_analyser.c Unity/src/unity.c -fsanitize=address -g3

*/
