# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: troberts <troberts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 01:33:16 by troberts          #+#    #+#              #
#    Updated: 2022/07/11 16:39:38 by troberts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                              VARIABLE REFERENCE                              #
# **************************************************************************** #

NAME= libft.a

CFLAGS= -Wall -Wextra -Werror -I $(INCLUDES)

AR= ar
ARARCH= -cr
ARINDEX= -s

INCLUDES= include
OBJ_DIR= obj
SRC_DIR= src

# **************************************************************************** #
#                                .C & .H FILES                                 #
# **************************************************************************** #

SRC=	$(SRC_DIR)/ft_atoi.c	\
		$(SRC_DIR)/ft_atol.c	\
		$(SRC_DIR)/ft_atoll.c	\
		$(SRC_DIR)/ft_bzero.c	\
		$(SRC_DIR)/ft_calloc.c	\
		$(SRC_DIR)/ft_isalnum.c	\
		$(SRC_DIR)/ft_isalpha.c	\
		$(SRC_DIR)/ft_isascii.c	\
		$(SRC_DIR)/ft_isdigit.c	\
		$(SRC_DIR)/ft_isprint.c	\
		$(SRC_DIR)/ft_isspace.c	\
		$(SRC_DIR)/ft_itoa.c	\
		$(SRC_DIR)/ft_lstadd_back.c	\
		$(SRC_DIR)/ft_lstadd_front.c	\
		$(SRC_DIR)/ft_lstclear.c	\
		$(SRC_DIR)/ft_lstdelone.c	\
		$(SRC_DIR)/ft_lstiter.c	\
		$(SRC_DIR)/ft_lstlast.c	\
		$(SRC_DIR)/ft_lstmap.c	\
		$(SRC_DIR)/ft_lstnew.c	\
		$(SRC_DIR)/ft_lstsize.c	\
		$(SRC_DIR)/ft_memalloc.c	\
		$(SRC_DIR)/ft_memccpy.c	\
		$(SRC_DIR)/ft_memchr.c	\
		$(SRC_DIR)/ft_memcmp.c	\
		$(SRC_DIR)/ft_memcpy.c	\
		$(SRC_DIR)/ft_memdel.c	\
		$(SRC_DIR)/ft_memmove.c	\
		$(SRC_DIR)/ft_memrchr.c	\
		$(SRC_DIR)/ft_memset.c	\
		$(SRC_DIR)/ft_printf_itoa_nbrlen.c	\
		$(SRC_DIR)/ft_printf_print_char.c	\
		$(SRC_DIR)/ft_printf_print_int.c	\
		$(SRC_DIR)/ft_printf_print_lower_hex.c	\
		$(SRC_DIR)/ft_printf_print_ptr.c	\
		$(SRC_DIR)/ft_printf_print_str.c	\
		$(SRC_DIR)/ft_printf_print_unsigned.c	\
		$(SRC_DIR)/ft_printf_print_upper_hex.c	\
		$(SRC_DIR)/ft_printf.c	\
		$(SRC_DIR)/ft_putchar.c	\
		$(SRC_DIR)/ft_putchar_fd.c	\
		$(SRC_DIR)/ft_putendl.c	\
		$(SRC_DIR)/ft_putendl_fd.c	\
		$(SRC_DIR)/ft_putnbr.c	\
		$(SRC_DIR)/ft_putnbr_fd.c	\
		$(SRC_DIR)/ft_putstr.c	\
		$(SRC_DIR)/ft_putstr_fd.c	\
		$(SRC_DIR)/ft_split.c	\
		$(SRC_DIR)/ft_strcat.c	\
		$(SRC_DIR)/ft_strchr.c	\
		$(SRC_DIR)/ft_strclr.c	\
		$(SRC_DIR)/ft_strcmp.c	\
		$(SRC_DIR)/ft_strcpy.c	\
		$(SRC_DIR)/ft_strdel.c	\
		$(SRC_DIR)/ft_strdup.c	\
		$(SRC_DIR)/ft_strequ.c	\
		$(SRC_DIR)/ft_striter.c	\
		$(SRC_DIR)/ft_striteri.c	\
		$(SRC_DIR)/ft_strjoin.c	\
		$(SRC_DIR)/ft_strlcat.c	\
		$(SRC_DIR)/ft_strlcpy.c	\
		$(SRC_DIR)/ft_strlen.c	\
		$(SRC_DIR)/ft_strmap.c	\
		$(SRC_DIR)/ft_strmapi.c	\
		$(SRC_DIR)/ft_strncat.c	\
		$(SRC_DIR)/ft_strncmp.c	\
		$(SRC_DIR)/ft_strncpy.c	\
		$(SRC_DIR)/ft_strnequ.c	\
		$(SRC_DIR)/ft_strnew.c	\
		$(SRC_DIR)/ft_strnstr.c	\
		$(SRC_DIR)/ft_strrchr.c	\
		$(SRC_DIR)/ft_strstr.c	\
		$(SRC_DIR)/ft_strtrim.c	\
		$(SRC_DIR)/ft_substr.c	\
		$(SRC_DIR)/ft_tolower.c	\
		$(SRC_DIR)/ft_toupper.c	\
		$(SRC_DIR)/get_next_line.c


OBJ=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# **************************************************************************** #
#                                HEADER CONFIG                                 #
# **************************************************************************** #

#                 # <-- start here          | <-- middle            # <-- stop here
HEADER_NAME 	= +                       Libft                     #

COLOR_RED		= \033[0;31m
COLOR_GREEN		= \033[0;32m
COLOR_YELLOW	= \033[0;33m
COLOR_BLUE		= \033[0;34m
COLOR_PURPLE	= \033[0;35m
COLOR_CYAN		= \033[0;36m
COLOR_WHITE		= \033[0;37m
COLOR_END		= \033[m

HEADER =			@echo "${COLOR_CYAN}\
					\n/* ************************************************************************** */\
					\n/*                                                                            */\
					\n/*            :::      ::::::::                                               */\
					\n/*          :+:      :+:    :+:                                               */\
					\n/*        +:+ +:+         +:${HEADER_NAME}*/\
					\n/*      +\#+  +:+       +\#+                                                    */\
					\n/*    +\#+\#+\#+\#+\#+   +\#+                       Thomas Robertson                */\
					\n/*         \#+\#    \#+\#                     <troberts@student.42.fr>            */\
					\n/*        \#\#\#   \#\#\#\#\#\#\#\#.fr                                                   */\
					\n/*                                                                            */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_LIBRARY =	@echo "${COLOR_YELLOW}\
					\n/* ************************************************************************** */\
					\n/*                          CREATING STATIC LIBRARY...                        */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_CLEAN =		@echo "${COLOR_RED}\
					\n/* ************************************************************************** */\
					\n/*                                 CLEANING...                                */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_FCLEAN =		@echo "${COLOR_RED}\
					\n/* ************************************************************************** */\
					\n/*                              FORCE CLEANING...                             */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_NORM =		@echo "${COLOR_PURPLE}\
					\n/* ************************************************************************** */\
					\n/*                            CHECKING THE NORM...                            */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"


# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	$(HEADER)
	$(HEADER_LIBRARY)
	@$(AR) $(ARARCH) $@ $^
	@$(AR) $(ARINDEX) $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

header:
	$(HEADER)

cleanobj:
	${HEADER_CLEAN}
	@rm -f $(OBJ)

cleanobjdir: cleanobj
	@rm -rf $(OBJ_DIR)

clean: header cleanobjdir
	
fclean: header clean
	${HEADER_FCLEAN}
	@rm -f $(NAME)

norm: header
	${HEADER_NORM}
	@echo "$(COLOR_CYAN)"
	norminette $(SRC_DIR) | awk "!/: OK!/"
	@echo "$(COLOR_PURPLE)"
	norminette $(INCLUDES) | awk "!/: OK!/"
	@echo "$(COLOR_END)"

re: header fclean all

.PHONY: all clean fclean re norm header cleanobj cleanobjdir
