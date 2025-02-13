NAME := minishell

### LIBFT #####################################################################

PATH_LIBFT := libft/

LIBFT := $(PATH_LIBFT)libft.a

### SRCS ######################################################################

PATH_SRCS += srcs/
PATH_SRCS += srcs/minishell_main_routine
PATH_SRCS += srcs/exit_routines
PATH_SRCS += srcs/user_interface
PATH_SRCS += srcs/history
PATH_SRCS += srcs/syntax_analysis
PATH_SRCS += srcs/lexical_analysis
PATH_SRCS += srcs/syntax_analysis
PATH_SRCS += srcs/environment_management
PATH_SRCS += srcs/environment_building
PATH_SRCS += srcs/semantic_analysis
PATH_SRCS += srcs/expander
PATH_SRCS += srcs/command_interpretation
PATH_SRCS += srcs/builtins
PATH_SRCS += srcs/execution_status

PATH_SRCS += srcs/functions_for_debug

# srcs/minishell_main_routine

SRCS += main.c
SRCS += core_routine.c
SRCS += clean_current_loop_context.c
SRCS += is_empty_input.c
SRCS += display_minishell_header.c

# srcs/exit_routines

SRCS += exit_shell_routine.c

# scrs/user_interface

SRCS += signals.c
SRCS += prompt.c

# srcs/history

SRCS += add_history.c

# srcs/lexing

SRCS += lexe_input.c
SRCS += tokenizer.c
SRCS += add_token_to_token_list.c
SRCS += create_token.c
SRCS += delete_token.c
SRCS += delete_token_list.c

SRCS += tokenize_operator.c
SRCS += tokenize_word.c
SRCS += get_last_lexem_size.c
SRCS += lexer_utils.c

# srcs/parsing

SRCS += parser.c

# srcs/environment_management

SRCS += get_environment.c
SRCS += set_variable.c
SRCS += set_variable_from_keyvalue.c
SRCS += create_variable.c
SRCS += update_variable.c
SRCS += add_variable_to_environment.c
SRCS += delete_variable.c
SRCS += delete_variables_list.c
SRCS += find_variable_from_key.c
SRCS += get_variable_key.c
SRCS += get_variable_value.c
SRCS += delete_variables_list_in_environment.c
SRCS += find_variable_in_environment_from_key.c
SRCS += set_variable_from_keyvalue_to_environment.c
SRCS += set_variable_to_environment.c

# srcs/environment_building

SRCS += build_environment.c

# srcs/semantic_analysis

SRCS += create_command.c
SRCS += assignation_checker.c
SRCS += semantic_analyzer.c
SRCS += state_assignation.c
SRCS += state_input_redirection.c
SRCS += state_output_redirection.c
SRCS += save_opening_error.c
SRCS += state_append_redirection.c
SRCS += state_heredoc.c
SRCS += state_command.c
SRCS += state_end_of_command.c
SRCS += get_command_name.c
SRCS += is_builtin.c
SRCS += delete_command_pipeline.c
SRCS += setup_pipe.c

# srcs/command_interpretation

SRCS += add_env_to_env.c
SRCS += add_command_env_to_shell_env.c
SRCS += command_interpreter.c
SRCS += launch_builtin.c
SRCS += command_path_manager.c
SRCS += build_complete_path.c
SRCS += execute_command.c
SRCS += list_to_strs_array.c
SRCS += args_list_to_args_array.c
SRCS += env_list_to_env_array.c
SRCS += exportable_env_list_to_strs_array.c
SRCS += check_complete_path.c
SRCS += command_process.c
SRCS += clean_command_process.c
SRCS += close_command_pipeline.c

# srcs/builtins

SRCS += env.c
SRCS += export.c
SRCS += display_sorted_exportables_variables.c
SRCS += pwd.c

# srcs/expander/

SRCS += expand_input.c
SRCS += expand_tilde.c
SRCS += expand_variable.c
SRCS += expand_word.c
SRCS += no_expand.c
SRCS += get_variable_from_env.c
SRCS += quote.c
SRCS += expander_exit.c
SRCS += erase_quotes.c

# srcs/exit_status

SRCS += set_exit_status.c
SRCS += get_exit_status_value.c

# print_functions to use for debug and tests

SRCS += print_env.c
SRCS += print_token.c
SRCS += print_token_list.c
SRCS += print_argument.c
SRCS += print_arguments_list.c
SRCS += print_command.c
SRCS += print_command_pipeline_list.c

vpath %.c $(PATH_SRCS)

### TESTS SRCS ################################################################

TESTS_NAME := features_tests

TESTS_SRCS_DIR += ./tests
TESTS_SRCS_DIR += ./tests/tests_lexical_analysis
TESTS_SRCS_DIR += ./tests/tests_syntax_analysis
TESTS_SRCS_DIR += ./tests/tests_lexical_analysis/BDD
TESTS_SRCS_DIR += ./tests/tests_lexical_analysis/unit_tests
TESTS_SRCS_DIR += ./tests/tests_syntax_analysis/BDD
TESTS_SRCS_DIR += ./tests/tests_environment_management
TESTS_SRCS_DIR += ./tests/tests_environment_management/unit_tests
TESTS_SRCS_DIR += ./tests/tests_environment_building
TESTS_SRCS_DIR += ./tests/tests_environment_building/unit_tests
TESTS_SRCS_DIR += ./tests/tests_semantic_analysis
TESTS_SRCS_DIR += ./tests/tests_semantic_analysis/unit_tests
TESTS_SRCS_DIR += ./tests/tests_semantic_analysis/behavior_tests
TESTS_SRCS_DIR += ./tests/tests_command_interpretation
TESTS_SRCS_DIR += ./tests/tests_command_interpretation/unit_tests

TESTS_SRCS += tests_main.c

# lexing

TESTS_SRCS += lexing_bdd.c
TESTS_SRCS += lexing_bdd_just_a_space.c
TESTS_SRCS += lexing_bdd_just_one_char.c
TESTS_SRCS += lexing_bdd_pipe_and_input_redir.c
TESTS_SRCS += lexing_bdd_pipe_and_redirs.c
TESTS_SRCS += lexing_bdd_operators_and_char.c
TESTS_SRCS += lexing_bdd_heredoc.c
TESTS_SRCS += lexing_bdd_just_one_word.c
TESTS_SRCS += lexing_bdd_two_words.c
TESTS_SRCS += lexing_bdd_word_with_double_quotes.c
TESTS_SRCS += lexing_bdd_word_with_simple_quotes.c

TESTS_SRCS += test_create_token.c

# parsing

TESTS_SRCS += parsing_bdd.c
TESTS_SRCS += test_empty_string.c
TESTS_SRCS += test_just_a_pipe.c
TESTS_SRCS += test_two_pipes.c
TESTS_SRCS += free_parser_test.c

# environment management

TESTS_SRCS += unit_tests_environment.c
TESTS_SRCS += test_create_variable.c
TESTS_SRCS += test_add_variable_to_variables_list.c
TESTS_SRCS += delete_variables_list_tests_version.c
TESTS_SRCS += test_get_variable_key.c
TESTS_SRCS += test_get_variable_value.c

# environemt building

TESTS_SRCS += unit_tests_environment_building.c

# semantic analysis

TESTS_SRCS += unit_tests_semantic_analyzer.c
TESTS_SRCS += tests_assignation_checker.c
TESTS_SRCS += tests_state_assignation.c
TESTS_SRCS += tests_state_input_redirection.c
TESTS_SRCS += tests_state_output_redirection.c
TESTS_SRCS += tests_state_append_redirection.c
TESTS_SRCS += tests_state_heredoc.c
TESTS_SRCS += tests_state_command.c

# command_interpretation

# TESTS_SRCS += tests_add_env_to_env.c

# Unity

UNITY_SRCS := Unity/src/unity.c

vpath %.c $(TESTS_SRCS_DIR)

### OBJS ######################################################################

PATH_OBJS := objs/

OBJS := $(patsubst %.c, $(PATH_OBJS)%.o, $(SRCS))

### TESTS_OBJS ################################################################

PATH_TESTS_OBJS := objs/tests/

TESTS_OBJS := $(patsubst %.c, $(PATH_TESTS_OBJS)%.o, $(TESTS_SRCS))


### HEADERS ###################################################################

PATH_INCLUDES := includes/
PATH_INCLUDES_LIBFT := $(PATH_LIBFT)includes/
PATH_INCLUDES_TESTS := includes/
PATH_INCLUDES_UNITY := ./Unity/src

HEADERS += $(PATH_INCLUDES)minishell.h
HEADERS += $(PATH_INCLUDES)history.h
HEADERS += $(PATH_INCLUDES)user_interface.h
HEADERS += $(PATH_INCLUDES)environment.h
HEADERS += $(PATH_INCLUDES)lexing.h
HEADERS += $(PATH_INCLUDES)parsing.h
HEADERS += $(PATH_INCLUDES)semantic.h
HEADERS += $(PATH_INCLUDES)command_interpretation.h

### COMPILATION ################################################################

CC := cc

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

ifeq ($(d), 1)
	CFLAGS += -fsanitize=address,undefined -g3
endif

ifeq ($(d), 2)
	CFLAGS += -g3
endif

ifeq ($(d), 3)
	CC = clang
	CFLAGS = -Weverything
endif

### RL_FLAG ####################################################################

RL_FLAG := -lreadline

### COLORS #####################################################################

GREEN := \033[0;32m
BLUE := \033[0;34m
WHITE := \033[0;37m

### LINT #######################################################################

CLANG_ANALYZE_OPTIONS = --analyze \
						-Weverything \
						-Wno-unknown-warning-option \
						-Werror \
						-ferror-limit=0 \
						-Xanalyzer -analyzer-output=text \
						-Xanalyzer -analyzer-config \
						-Xanalyzer aggressive-binary-operation-simplification=true \
						-Xanalyzer -analyzer-config \
						-Xanalyzer unroll-loops=true

CPPCHECK_OPTIONS =  --enable=all \
					--inconclusive \
					--error-exitcode=1 \
					--suppress=missingIncludeSystem \
					--suppress=variableScope

### RULES ######################################################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(BLUE)Compiling $(NAME)...$(WHITE)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_LIBFT) $(RL_FLAG)
	@echo "$(GREEN)$(NAME) Compiled !$(WHITE)"

$(OBJS): $(PATH_OBJS)%.o: %.c $(HEADERS)
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_LIBFT)

$(TESTS_OBJS): $(PATH_TESTS_OBJS)%.o: %.c $(HEADERS)
	@mkdir -p $(PATH_TESTS_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INCLUDES_TESTS) -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_LIBFT) -I $(PATH_INCLUDES_UNITY)


$(LIBFT):
	@echo "$(BLUE)Compiling $(LIBFT) ...$(WHITE)"
	@$(MAKE) -sC $(PATH_LIBFT)
	@echo "$(GREEN)$(LIBFT) Compiled ! $(WHITE)"

clean:
	@echo "$(BLUE)Cleaning $(NAME) ...$(WHITE)"
	@$(RM) -r $(PATH_OBJS)
	@$(MAKE) -sC $(PATH_LIBFT) clean
	@echo "$(GREEN)$(NAME) Cleaned ! $(WHITE)"

fclean: clean
	@echo "$(BLUE)Full Cleaning $(NAME) ...$(WHITE)"
	@$(RM) $(NAME)
	@$(RM) $(TESTS_NAME)
	@$(MAKE) -sC $(PATH_LIBFT) fclean
	@echo "$(GREEN)$(NAME) Fully Cleaned ! $(WHITE)"

re: fclean all

install_hooks:
	.scripts/install_hooks.sh

norminette: $(SRCS) $(HEADERS)
	norminette $^

tests: $(LIBFT) $(TESTS_OBJS) $(filter-out $(PATH_OBJS)main.o, $(OBJS)) $(UNITY_SRCS)
	@echo "$(BLUE)Features tests...$(WHITE)"
	$(CC) $(CFLAGS) $(RL_FLAG) -I $(PATH_INCLUDES_TESTS) -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_UNITY) -I $(PATH_INCLUDES_LIBFT) $^ -o $(TESTS_NAME) -L$(PATH_LIBFT) -lft -DTEST_MODE

#$(CC) $(CFLAGS) $(RL_FLAG) -I $(PATH_INCLUDES_TESTS) -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_UNITY) -I $(PATH_INCLUDES_LIBFT) -o $(TESTS_NAME) $^ -DTEST_MODE

environment_tests:
	@echo "$(BLUE)Environment tests...$(WHITE)"
	@./e2e/launch_environment_tests.test.sh
	@echo "$(GREEN)Environment tests passed !$(WHITE)"

.PHONY: all clean fclean re cppcheck clang_analyzer norminette tests
