# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: argomez <argomez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 16:56:39 by argomez           #+#    #+#              #
#    Updated: 2022/11/25 17:47:35 by argomez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define display_compilation 
	@echo "\e[94m     *\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*"
	@echo "\e[34m     *                              \e[94m*"
	@echo "\e[94m     *  \e[96mLibft Compilation Complete\e[0m  \e[34m*"
	@echo "\e[34m     *                              \e[94m*"
	@echo "\e[94m     *\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[0m"
endef

define display_clean 
	@echo "\e[94m     *\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*"
	@echo "\e[34m     *                              \e[94m*"
	@echo "\e[94m     *     \e[96mLibft Clean Complete     \e[34m*"
	@echo "\e[34m     *                              \e[94m*"
	@echo "\e[94m     *\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[94m*\e[34m*\e[0m"
endef


NAME		=	libft.a

P_CHARS		=	chars/

CHARS		=	ft_isalnum			\
				ft_isalpha			\
				ft_isascii			\
				ft_isdigit			\
				ft_isprint			\
				ft_tolower			\
				ft_toupper			\

P_DISPLAYS	=	displays/

DISPLAYS	=	ft_putchar_fd		\
				ft_putendl_fd		\
				ft_putnbr_fd		\
				ft_putstr_fd		\

P_LISTS		=	lists/

LISTS		=	ft_lstadd_back		\
				ft_lstadd_front		\
				ft_lstclear			\
				ft_lstdelone		\
				ft_lstiter			\
				ft_lstlast			\
				ft_lstmap			\
				ft_lstnew			\
				ft_lstsize			\

P_MEMORIES	=	memories/

MEMORIES		=	ft_bzero		\
				ft_calloc			\
				ft_memchr			\
				ft_memcmp			\
				ft_memcpy			\
				ft_memmove			\
				ft_memset			\

P_STRS		=	strs/

STRS		=	ft_split			\
				ft_strchr			\
				ft_strchrc			\
				ft_strdup			\
				ft_striteri			\
				ft_strjoin			\
				ft_strjoin_char		\
				ft_strlcat			\
				ft_strlcpy			\
				ft_strlen			\
				ft_strmapi			\
				ft_strncmp			\
				ft_strcmp			\
				ft_strnstr			\
				ft_strrchr			\
				ft_strtrim			\
				ft_substr			\
				ft_extension		\
				

P_UTILS		=	utils/

UTILS		=	ft_atoi				\
				ft_itoa				\
				is_tab_sorted		\
				ft_btod				\
				ft_sort_int_tabs	\

P_PRINTF	=	printf/

PRINTF		=	ft_printf			\
				ft_printf_char		\
				ft_printf_decimal	\
				ft_printf_hexa		\
				ft_printf_nbr		\
				ft_printf_ptr		\
				ft_printf_str		\
				ft_printf_unsigned	\

P_PRINTF_FD	=	printf_fd/

PRINTF_FD	=	ft_printf_fd		\
				displays			\
				print_decimal		\
				print_hexadecimal	\
				print_number		\
				print_pointer		\
				print_string		\

P_GNL		=	gnl/

GNL			=	get_next_line		\
				get_next_line_utils	\

C_TYPE		=	.c
H_TYPE		=	.h

AR			=	ar rcs -o
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f

SRC			=	$(addprefix $(P_CHARS), $(addsuffix $(C_TYPE), $(CHARS)))		\
				$(addprefix $(P_DISPLAYS), $(addsuffix $(C_TYPE), $(DISPLAYS)))	\
				$(addprefix $(P_LISTS), $(addsuffix $(C_TYPE), $(LISTS)))		\
				$(addprefix $(P_MEMORIES), $(addsuffix $(C_TYPE), $(MEMORIES)))	\
				$(addprefix $(P_STRS), $(addsuffix $(C_TYPE), $(STRS)))			\
				$(addprefix $(P_UTILS), $(addsuffix $(C_TYPE), $(UTILS)))		\
				$(addprefix $(P_PRINTF), $(addsuffix $(C_TYPE), $(PRINTF)))		\
				$(addprefix $(P_PRINTF_FD), $(addsuffix $(C_TYPE), $(PRINTF_FD)))		\
				$(addprefix $(P_GNL), $(addsuffix $(C_TYPE), $(GNL)))			\

OBJ			=	$(SRC:.c=.o)

.c.o: $(SRC)
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)
	
$(NAME):	$(OBJ)
	@ar rcs -o $(NAME) $(OBJ)
	$(display_compilation)

clean:
	@ $(RM) $(OBJ)
	$(display_clean)

fclean:	clean
	@ $(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
