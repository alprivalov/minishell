##### Compilation ##############################################################
## compile avec clang ##
# Commands:
AR			= ar rcs -o
CC			= clang	
CFLAGS		= -Wall -Werror -Wextra -g
RM			= rm -rf

# Includes:
INCLUDES	= -lreadline $(LIBFT)
LIBFT		= includes/libft/libft.a

# SRCS:
NAME		= minishell
FILES		=	minishell.c \
				ft_free.c \
				get_path.c \
				ft_free_cmd.c \
				ft_print_list.c \

# INIT:
INIT  		=	ft_init_vars.c \
				ft_init_cmd.c \
				ft_init_vars_minishell.c \
				ft_init_heredocs.c	\
				ft_init_list_type.c \

# CMD
CMD			= 	ft_command.c \
				ft_cmd_infile.c \
				simple_execve_redir.c \
				ft_child_parent.c \
				ft_first_mid_last_cmd.c \
				ft_fd_redirect.c \
				ft_exec_cmd.c \
				ft_waitpid.c \
# UTILS
UTILS		=	ft_is_space.c				\
				ft_substr_shell.c			\
				ft_strjoin_sh.c				\
				ft_lst_env.c				\
				ft_substr_env.c				\
				ft_itoa_sh.c				\
				heredoc/heredoc.c			\
				heredoc/manage_heredoc.c	\
				ft_strjoin_frees.c			\
				multi_join.c				\
				ft_split_sh.c				\
				ft_new_list_sh.c			\
				find_in_env.c				\
# BUILTINS
BUILTINS	=	ft_builtins.c \
				ft_cd.c	\
				ft_echo.c \
				ft_pwd.c \
				ft_unset.c	\
				ft_exit.c \

# BUILTINS_EXPORT
BUILTINS_EXPORT =	ft_export.c \
					ft_init_export.c \
					ft_add_char.c \
					ft_exp_ow_char.c \
					ft_extract_values.c \
# PARSING
PARSING =	parsing.c \
			ft_redirection.c \
			ft_parsing_dollars_quotes.c \
			ft_if_env_vars_exist.c \
			ft_parsing_dollars.c \
			ft_pars_d_quotes.c \
			ft_pars_s_quotes.c \
			ft_join_list.c \
			ft_parsing_env.c \
			ft_parsing_space.c \
			ft_pars_pipe.c \
			ft_pars_redirection.c \
			ft_pars_string.c \
			ft_parsing_type.c \
			ft_parsing_type_redir_l.c \
			ft_pars_nb_cmd.c \
			ft_parsing_redirection.c \
# OBJS
SRCS		=	$(addprefix srcs/, $(FILES))	\
				$(addprefix utils/, $(UTILS))	\
				$(addprefix srcs/builtins/, $(BUILTINS))	\
				$(addprefix srcs/builtins/export/, $(BUILTINS_EXPORT))	\
				$(addprefix srcs/parsing/, $(PARSING))	\
				$(addprefix srcs/cmd/, $(CMD))	\
				$(addprefix srcs/init/, $(INIT))	\

OBJS		= $(SRCS:.c=.o)

##### Rules ####################################################################

all: $(LIBFT) $(NAME)

$(LIBFT):
	@ make -C includes/libft --no-print-directory

libftfclean:
	@ make fclean -C includes/libft --no-print-directory

.c.o: $(SRCS)
	@ echo -n "\e[94m"
	$(CC) $(CFLAGS) -c -o $@ $< 
	@ echo -n "\e[39m"

clear:
	clear

$(NAME): $(OBJS)
	@ echo "\e[34m"
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)
	@ echo "\e[39m"

clean:
	@ echo -n "\e[38;5;208m"
	$(RM) $(OBJS)
	@ echo "\e[39m"

fclean: clear clean
	@ echo -n "\e[38;5;208m"
	$(RM) $(NAME)
	@ echo "\e[39m"

ffclean: clear fclean libftfclean

re: ffclean all 

rec: fclean $(NAME)
	@ make clean --no-print-directory

.PHONY: all clean fclean ffclean re clear rec
