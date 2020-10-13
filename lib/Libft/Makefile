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

NAME = Lib_FT
NAME_EXEC = libft.a
TABS = \t\t

CC = gcc
FLAGS = -Wall -Werror -Wextra

INCLUDES = -I$(HEADERS_DIR)

SRC_DIR = src/
SRC_LIST =	ft_atoi.c \
            ft_error.c \
            ft_count_words.c \
            ft_bzero.c \
            ft_del.c \
            ft_isalnum.c \
            ft_isalpha.c \
            ft_isascii.c \
            ft_isdigit.c \
            ft_isprint.c \
            ft_itoa.c \
            ft_bilstadd.c \
            ft_bilstadd_back.c \
            ft_bilstdel.c \
            ft_bilstdelone.c \
            ft_bilstnew.c \
            ft_bilstsort.c \
            ft_bilstswap.c \
            ft_bilstlength.c \
            ft_lstadd.c \
            ft_lstadd_back.c \
            ft_lstdel.c \
            ft_lstdel_pos.c \
            ft_lstdelone.c \
            ft_lstiter.c \
            ft_lstmap.c \
            ft_lstnew.c \
            ft_memalloc.c \
            ft_memccpy.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_memcpy.c \
            ft_memdel.c \
            ft_memmove.c \
            ft_memset.c \
            ft_putchar.c \
            ft_putchar_fd.c \
            ft_putendl.c \
            ft_putendl_fd.c \
            ft_putnbr.c \
            ft_putnbr_fd.c \
            ft_putstr.c \
            ft_putstr_fd.c \
            ft_strcat.c \
            ft_strchr.c \
            ft_strclr.c \
            ft_strcmp.c \
            ft_strcpy.c \
            ft_strdel.c \
            ft_strdup.c \
            ft_strequ.c \
            ft_striter.c \
            ft_striteri.c \
            ft_strjoin.c \
            ft_strlcat.c \
            ft_strlen.c \
            ft_strmap.c \
            ft_strmapi.c \
            ft_strncat.c \
            ft_strncmp.c \
            ft_strncpy.c \
            ft_strnequ.c \
            ft_strnew.c \
            ft_strnstr.c \
            ft_strrchr.c \
            ft_strsplit.c \
            ft_strstr.c \
            ft_strsub.c \
            ft_strtrim.c \
            ft_tolower.c \
            ft_toupper.c \
            get_next_line.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = obj/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

HEADERS_LIST = libft.h
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
