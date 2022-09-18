#*************************************************************************** #
#                                                                              #
#            :::      ::::::::                                                 #
#          :+:      :+:    :+:                                                 #
#        +:+ +:+         +:+         Makefile v2.0                             #
#      +#+  +:+       +#+                                                      #
#    +#+#+#+#+#+   +#+               By: troberts <troberts@student.42.fr>     #
#         #+#    #+#                                                           #
#        ###   ########.fr                                                     #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                              VARIABLE REFERENCE                              #
# **************************************************************************** #

NAME= pipex

# CC= gcc
# CC= clang
CFLAGS= -Wall -Wextra -Werror -g -I $(INCLUDES)

LIBFT_DIR= libft
LIBFT_LIB= $(LIBFT_DIR)/libft.a
INCLUDES= include
OBJ_DIR= obj/
SRC_DIR= src/

# **************************************************************************** #
#                                .C & .H FILES                                 #
# **************************************************************************** #

SRC_FILE=	\
			create_struct_cmd.c \
			fork.c \
			getpathenv.c \
			here_doc.c \
			main.c \
			split_options.c \
			utils.c

SRC=		$(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ_FILE= 	$(SRC_FILE:.c=.o)
OBJ=		$(addprefix $(OBJ_DIR), $(OBJ_FILE))

#OBJ=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# **************************************************************************** #
#                                HEADER CONFIG                                 #
# **************************************************************************** #

#                 # <-- start here         | <-- middle             # <-- stop here
HEADER_NAME 	= +                      pipex                      #

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

HEADER_COMPIL =	@echo "${COLOR_YELLOW}\
					\n/* ************************************************************************** */\
					\n/*                                 COMPILING...                               */\
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

HEADER_ENTERLIB =	@echo "${COLOR_GREEN}\
					\n/* ************************************************************************** */\
					\n/*                               ENTERING LIBFT                               */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_EXITLIB =	@echo "${COLOR_GREEN}\
					\n/* ************************************************************************** */\
					\n/*                               EXITING LIBFT                                */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	$(HEADER)
	$(HEADER_COMPIL)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT_LIB)

malloc_test: $(LIBFT_LIB) $(OBJ)
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ $(OBJ) $(LIBFT_LIB) -L. -lmallocator

$(LIBFT_LIB): makelibf ;

bonus: $(NAME)

makelibf :
	$(HEADER_ENTERLIB)
	@make -C $(LIBFT_DIR)
	$(HEADER_EXITLIB)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

header:
	$(HEADER)

cleanobj:
	${HEADER_CLEAN}
	rm -f $(OBJ) $(OBJ_BONUS) $(OBJ_COMMON)

cleanobjdir: cleanobj
	rm -rf $(OBJ_DIR)

clean: header cleanobjdir cleanlibft
	
cleanlibft:
	make -C $(LIBFT_DIR) clean

fcleanlibft:
	make -C $(LIBFT_DIR) fclean
	rm -f libft.a

fclean: header clean fcleanlibft
	${HEADER_FCLEAN}
	rm -f $(NAME) $(NAME_BONUS)

re: header fclean all

norm: header
	${HEADER_NORM}
	@echo "$(COLOR_GREEN)"
	-python3 -m norminette $(LIBFT_DIR) | awk "!/: OK!/"
	@echo "$(COLOR_CYAN)"
	-python3 -m norminette $(SRC_DIR)
	@echo "$(COLOR_PURPLE)"
	-python3 -m norminette $(INCLUDES)
	@echo "$(COLOR_END)"

.PHONY: all clean fclean re norm header makelibf cleanobj cleanobjdir fcleanlibft bonus
