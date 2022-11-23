/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:04:40 by marcrodr          #+#    #+#             */
/*   Updated: 2022/11/23 18:54:39 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H 

# include "libft.h"
# include <fcntl.h>
# include <signal.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>

# define CYAN "\001\033[1;36m\002"
# define WHITE "\001\033[0m\002"
# define GREEN "\001\033[1;32m\002"

# define D_QUOTE '\"'
# define QUOTE '\''
# define D_QUOTE_S "\""
# define QUOTE_S "\'"

# define PROMPT "❍ "

/*
**  Macros to define some messages error
*/
# define ERROR_DIR "No such file or directory\n"



int		g_ret_number;

typedef	struct	s_nenv
{
	char			*var;
	char			*content;
	struct s_nenv	*next;
}	t_nenv;

typedef struct	s_env
{
	unsigned long int	size;
	struct s_nenv		*top_node;
	int					index;
}	t_env;

typedef struct s_split
{
	int	qtt_comand;
	int	ini;
	int len;
	int quote;
	int	qtt_pipe;	
}		t_split;

typedef struct s_token
{
	char	*print;
	char	*exec;
	char	quote;
	char	*end;
	char	*new;
	int		i;
	int		init;
	int		len;
	int		posic;	
}			t_token;



typedef struct s_minishell
{
	char		*line;
	int			c;
	int			out_fd;
	bool		is_builtin;
	bool		flag;
	int			redirect;
	int			input_fd;
	char		*name_file;
	char		*error_name_file;
	int			append;
	char		*commands[50];
	char		**tokens;
	t_env		envp;
	t_token		token;
	t_split		split;
}				t_minishell;

int	g_ret_number;

t_nenv	*ft_node_format(t_nenv	*node);
void	ft_initialize_list(t_env *env_list);
void	ft_more_envp(t_env *env_list, char **env);
t_env	initialize_env(char **envp);

// FUNCTIONS
int 	check_args(int argc);

// SIGNALS
void	define_signals(void);
void	run_signals(int sig);
void	ctrl_c(int sig);
void	back_slash(int sig);

// BUILT-INS
void	is_builtin(t_minishell *mini, char *cmd);
void	ft_env(t_env *env_list);
void	ft_pwd(t_env *env_list);
void	ft_echo(t_env *cmd_line);



// UTILS
char	*skip_space(char *str);
void	init_split(t_minishell *mini);
void	ft_print_ppc(char  **splited, int aux);
void	get_home_sign(t_minishell *mini, t_token *tk);
void	get_dollar_sign(t_minishell *mini, t_token *tk);
int		count_pipe(t_minishell *mini, char *cmd, int i);
void	free_array(char **array);
void	free_tk(t_token *tk);
char	*find_env(t_minishell *mini, char *env);
void	finish_tokenizer(t_minishell *mini, t_token *tk);
int		tokenizer_find_char(char *string, char needle);
void	check_flags(t_minishell *mini, char *in, int i, int c);
t_token	*init_tk();

// PARSER
void	split_cmd(t_minishell *mini, char *cmd, int i);
void	run_commands_aux(t_minishell *mini);
void	exec_commands(t_minishell *mini);
void	tokenizer(t_minishell *mini);
void	action(t_minishell *mini);

// EXEC
void	redirect_out(t_minishell *mini, int i);
void	redirect_in(t_minishell *mini, int c, char *aux);
void	simple_redir_out(t_minishell *mini, int i, int flags);
char	**re_redir(t_minishell *mini, char **file, int c);
char	*new_comman(int i, char **file);
void	read_until(char *file);
int		find_char(char *str, char wanted);
void	exec_process(t_minishell *mini, int in_fd, int out_fd);
void	run_builtin(t_minishell *mini);

#endif
