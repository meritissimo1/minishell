# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 09:12:07 by marcrodr          #+#    #+#              #
#    Updated: 2022/09/19 14:25:46 by marcrodr         ###   ########.fr        #
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
UTILS_SRC	= utils_env.c

SRCS		=	$(MAIN_SRC) \
				$(addprefix $(ERROR_DIR)/, $(ERROR_SRC)) \
				$(addprefix $(SIGNAL_DIR)/, $(SIGNAL_SRC)) \
				$(addprefix $(UTILS_DIR)/, $(UTILS_SRC))

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
	$(RM) $(NAME)
	
re: fclean all

.PHONY: re fclean clean all