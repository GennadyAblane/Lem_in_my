#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 12:48:11 by esnowpea          #+#    #+#              #
#    Updated: 2019/12/27 20:21:42 by esnowpea         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = Lib_FT_Printf
NAME_EXEC = libftprintf.a
TABS = \t

CC = gcc
FLAGS = -Wall -Werror -Wextra

LIBFT = Lib_FT
LIBFT_EXEC = $(LIBFT_DIR)libft.a
LIBFT_DIR = ../Libft/
LIBFT_HEADERS = $(LIBFT_DIR)inc/

INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS)

SRC_DIR = src/
SRC_LIST =	ft_printf.c \
			parsing.c \
			ft_c.c \
			ft_s.c \
			ft_d.c \
			ft_f.c \
			ft_e.c \
			ft_g.c \
			ft_itoa_long.c \
			itoa_double.c \
			mult_double.c \
			rounding.c \
			handler_flags.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = obj/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

HEADERS_LIST = printf.h
HEADERS_DIR = ./inc/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

# COLORS

GRN = \033[0;32m
RED = \033[0;31m
YEL = \033[1;33m
END = \033[0m

all: $(NAME_EXEC)

$(NAME_EXEC): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME_EXEC) $(OBJ)
	@ranlib $(NAME_EXEC)
	@echo "\n$(NAME):$(TABS)$(GRN)library created$(END)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME):$(TABS)$(GRN)$(OBJ_DIR) created$(END)"

clean:
	@rm -rf $(OBJ_DIR)
ifneq ($(strip $(wildcard $(OBJ))),)
	@echo "$(NAME):$(TABS)$(RED)*.o files deleted$(END)"
	@echo "$(NAME):$(TABS)$(RED)$(OBJ_DIR) deleted$(END)"
endif

fclean: clean
	@rm -f $(NAME_EXEC)
ifneq ($(strip $(wildcard $(NAME_EXEC))),)
	@echo "$(NAME):$(TABS)$(RED)$(NAME_EXEC) deleted$(END)"
endif

re: fclean all
