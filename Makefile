# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 09:12:07 by marcrodr          #+#    #+#              #
#    Updated: 2022/11/16 13:43:31 by marcrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror

## Main Header
INCS		= minishell.h
INCS_DIR	= includes
MAIN_HEADER	= $(addprefix $(INCS_DIR)/, $(INCS))

## Libft
LIBFT_DIR	= libft
LIBFT		= libft.h
## Includes
INC_FLAGS	= -I $(INCS_DIR) -I $(LIBFT_DIR)

## Source
SRCS_DIR	= ./src
MAIN_SRC	= main.c

## Error
ERROR_DIR	= error
ERROR_SRC	= check_args.c

## Signal
SIGNAL_DIR	= signals
SIGNAL_SRC	= signal.c

## Utils
UTILS_DIR	= utils
UTILS_SRC	= init_env.c is_char_validated.c utils.c free_array.c

## Built-ins
BUILT_DIR	= builtins
BUILT_SRC	= ft_env.c ft_pwd.c  ft_echo.c is_builtin.c

## Parser
PARSER_DIR	= parser
PARSER_SRC	= parser_split.c get_cmdtable.c

## Exec
EXEC_DIR = exec
EXEC_SRC = exec_commands.c redirect_out.c redirect_in.c

SRCS		=	$(MAIN_SRC) \
				$(addprefix $(ERROR_DIR)/, $(ERROR_SRC)) \
				$(addprefix $(SIGNAL_DIR)/, $(SIGNAL_SRC)) \
				$(addprefix $(UTILS_DIR)/, $(UTILS_SRC)) \
				$(addprefix $(BUILT_DIR)/, $(BUILT_SRC)) \
				$(addprefix $(PARSER_DIR)/, $(PARSER_SRC)) \
				$(addprefix $(EXEC_DIR)/, $(EXEC_SRC))
				
SRCS_PATH	= $(addprefix $(SRCS_DIR)/, $(SRCS)) ## src/*

OBJS_DIR	= ./objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
DIR_OBJS	= mkdir -p $(@D)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(DIR_OBJS)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

## Targets
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) libft/libft.a -lreadline -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	@make $@ -C $(LIBFT_DIR)
	$(RM) $(NAME) debug
	
re: fclean all

debug:
	@make -C $(LIBFT_DIR)
	$(CC) -g $(CFLAGS) $(INC_FLAGS) $(SRCS_PATH) libft/libft.a -lreadline -o $@
	gdb --tui ./$@

.PHONY: re fclean clean all
