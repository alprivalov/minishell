/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:46:34 by argomez           #+#    #+#             */
/*   Updated: 2022/12/27 17:47:02 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <termios.h>
# include <curses.h>
# include "libft/libft.h"

enum e_type_vars {
	CMD,
	OPTION,
	WHITE_SPACE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	S_REDIR_L,
	D_REDIR_L,
	S_REDIR_R,
	D_REDIR_R,
	ERROR,
	REDIR,
	DOLLARS,
	PIPE
};

extern int	g_ret_value;

typedef struct s_cmds
{
	int		cmd_number;
	char	*cmd;
	char	**args;
	char	**env;
	char	*infile;
	int		type_outfile;
	char	*outfile;
}	t_cmds;

typedef struct s_redirections
{
	char	*outfiles[4096];
	char	*heredocs[4096];
	int		index_name;
	int		index_heredoc;
	int		run;
}	t_redirections;

typedef struct s_list_sh
{
	char				*content;
	int					type_vars;
	struct s_list_sh	*next;
	struct s_list_sh	*preview;
}	t_list_sh;

typedef struct s_list_env
{
	char				*vars;
	char				*vars_value;
	char				*vars_all;
	int					len;
	struct s_list_env	*next;
	struct s_list_env	*preview;
}	t_list_env;

typedef struct s_datas
{
	char			*home_directory;
	int				index_current_cmd;
	t_list_sh		*current_cmd_redir;
	char			*cmd_outfile;
	char			*cmd_infile;
	int				index_pid;
	int				nb_pipe;
	char			*input_str;
	int				*pid;
	int				comp_input_str;
	int				**fd_pipe;
	char			**path_env;
	char			**env;
	char			pwd[PATH_MAX];
	t_cmds			*cmds;
	t_list_sh		*list;
	t_redirections	redirections;
	t_list_env		*env_sh;
}	t_datas;

typedef struct s_parsing
{
	int		type;
	int		pars_i;
	int		i;
	int		pars_start;
	int		error;
	char	*str_out;
}	t_pars;

// FREE

void		free_cmd(t_cmds *cmd);
void		free_fd_pipe(t_datas *data);
void		free_env(t_datas *data);
void		free_path_env(t_datas *data);
void		ft_free_env_list(t_list_env *list);
int			ft_free(t_datas *data, int option);
void		ft_free_list(t_list_sh *list);
void		ft_exit_childs(t_datas *data, int exit_code);

// UTILS

char		**ft_split_sh(char const *s, char c);
char		*ft_itoa_sh(int n);
void		ft_d_lstadd_back(t_list_sh *list, t_list_sh *new);
t_list_sh	*ft_d_lstlast(t_list_sh *lst);
t_list_sh	*ft_d_lstnew(char *str, int type_vars);
t_list_sh	*ft_d_lst(char *str, t_pars *vars);
void		ft_d_lstadd_back_env(t_list_env **env_sh, t_list_env *new);
t_list_env	*ft_d_lstlast_env(t_list_env *lst);
t_list_env	*ft_d_lstnew_env(char *str);
char		*ft_strjoin_sh(char const *s1, char const *s2);
char		*ft_substr_shell(char const *s, unsigned int start, size_t len);
char		*ft_substr_env(char const *s, unsigned int start, size_t len);
char		*ft_strcpy_env(char *dest, char *src);
char		*ft_strdup_env(const char *s);
char		*heredoc(char *prompt, char *limiter, t_datas *datas);
char		*ft_strjoin_frees(char *string_1, char *string_2, char option);
void		change_globale(int key);
char		*manage_heredocs(char *action, t_datas *datas);
void		no_limiter(char *prompt, char *str, int fd);
void		with_limiter(char *prompt, char *str, int fd, char *limiter);
char		*create_heredocs(t_datas *datas);
char		*delete_heredocs(t_datas *datas, int option);
char		*multi_join(int nb, char *to_free, ...);
char		*find_in_env(char *to_find, char **env);
int			is_in_env(char *to_find, char **env);

// PARSING

char		*check_env(t_list_env *env_sh, char *str);
void		ft_pars_env(t_list_env *env_sh, t_list_sh **tmp, t_pars	*vars);
void		ft_prinft_error(t_pars *vars, char c);
char		*cmd_line(t_list_sh *list);
void		list_next_cmd(t_list_sh **list);
void		ft_parsing_redirection(t_cmds *cmd, t_list_sh *list, t_datas *data);
t_list_sh	*ft_pars_str(t_list_env	*env_sh, t_datas *data, t_list_sh *list);
void		ft_is_right_redirec(t_pars *vars, t_datas *data);
void		ft_is_left_redirec(t_pars *vars, t_datas *data);
t_list_sh	*ft_parsing_dollars_quotes(t_list_env *env_sh, t_list_sh *list);
int			ft_is_alpha_num_underscore(char c);
t_list_sh	*ft_parsing_dollars(t_list_sh *list, t_pars *vars, t_datas *data);
t_list_sh	*ft_write_list(char *str_in, t_list_sh *list, t_pars *vars);
char		*ft_if_env_vars_exist(t_list_env *env_sh, t_list_sh **tmp);
t_list_sh	*ft_join_list(t_list_sh *list, t_list_sh *new_list);
t_list_sh	*ft_pars_dquotes(t_pars *vars, t_datas *data, t_list_sh *list);
t_list_sh	*ft_pars_redirection(t_pars *vars, t_datas *data, t_list_sh *list);
t_list_sh	*ft_pars_squotes(t_pars *vars, t_datas *data, t_list_sh *list);
t_list_sh	*ft_pars_pipe(t_pars *vars, t_datas *data, t_list_sh *list);
t_list_sh	*ft_pars_string(t_pars *vars, t_datas *data, t_list_sh *list);
int			ft_is_space(char c);
t_list_sh	*ft_parsing_space(t_pars *vars, t_datas *data, t_list_sh *list);

// BUILTINS

int			ft_builtins(t_list_env **env_sh, t_cmds *cmd, t_datas *data);
void		ft_unset(t_cmds *cmd, t_datas *data);
void		ft_pwd(t_datas *data);
void		ft_export(t_cmds *cmd, t_list_env **env_sh);
void		ft_echo(t_cmds *cmd);
void		ft_cd(t_cmds *cmd, t_datas *data);
void		ft_arg_builtins(t_cmds *cmd, t_list_sh *list,
				t_list_env **env_sh, t_datas *data);
char		*ft_init_export_no_plus(char *str);
char		*ft_init_export_plus(char *str);
void		ft_add_char(t_list_env **env_sh, char *vars, char *value_vars);
char		*ft_value_vars(char	*str, char *vars_export);
char		*ft_vars_exports(char	*str);
void		ft_exp_ow_char(t_list_env **env_sh, char *value, char *vars);
int			ft_export_exist(t_list_env **env_sh, char *vars_export);
char		*ft_init_before_str(char *str_in, int i);
t_cmds		*ft_init_cmd(t_cmds *cmds, t_datas *data, t_list_sh *list);
int			get_path(t_cmds *cmd, char **paths, t_datas *data);
void		ft_exit(t_cmds *cmd, t_datas *data);
int			ft_builtins_parent(t_list_env **env_sh, t_cmds *cmd, t_datas *data);

// PIPE

int			ft_command(t_cmds *cmd, t_datas *datas, t_list_env **env_sh);

// INIT.

int			ft_list_type(t_list_env *env, t_datas *data, t_list_sh **new_list);
void		ft_init_vars(t_pars	*vars);
void		ft_init_path_env(t_datas *data, t_list_env *env_sh);
void		ft_init_vars_ms(t_datas *data);
void		ft_malloc_fd_pipe(t_datas *data);
void		ft_init_list_env(t_list_env **env_sh, char **env, t_datas *data);
void		ft_init_heredocs(t_datas *datas);

// TYPE

void		ft_parsing_type(t_datas *datas, t_list_sh *new_list);
void		type_redir_l(t_list_sh **tmp);
void		type_redir_l_d(t_list_sh **tmp);
void		type_redir_r(t_list_sh **tmp);

// CMD

void		ft_waitpid(t_cmds *cmd, t_datas *data);
void		ft_exec_cmd(t_datas *data, t_list_sh *list, t_list_env *env_sh);
void		ft_child(t_cmds *cmd, t_datas *datas, t_list_env **env_sh);
void		ft_parent(t_cmds *cmd, t_datas *datas);
void		first_command(t_cmds *cmd, t_datas *datas, t_list_env **env_sh);
void		middle_command(t_cmds *cmd, t_datas *datas, t_list_env **env_sh);
void		last_command(t_cmds *cmd, t_datas *datas, t_list_env **env_sh);
void		close_redirection_fd(int fd_in, int fd_out, t_cmds *cmd);
int			ft_if_data_cmd_in(int fd_in, t_cmds *cmd);
int			ft_if_data_cmd_out(int fd_out, t_cmds *cmd);
void		exec_cmd_builtins(t_cmds *cmd, t_datas *datas, t_list_env **env_sh);
void		simple_command(t_cmds *cmd, t_datas *data, t_list_env **env_sh);

// OTHERS

void		ft_print_wrong_files(t_cmds *cmd, int i, t_datas *data);
void		ft_close_fd(t_datas *datas);
int			ft_fd_outfile(t_cmds *cmd);
int			ft_fd_infile(t_cmds *cmd);
void		ft_printf_list_env(t_cmds *cmd, t_list_env **env_sh);
void		sig_handler(int signal);
void		ft_printf_list_export(t_cmds *cmd, t_list_env **env_sh);
void		spec(int signal);

#endif