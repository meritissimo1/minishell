/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:04:40 by marcrodr          #+#    #+#             */
/*   Updated: 2022/11/16 15:41:24 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H 

# include "libft.h"
# include <fcntl.h>
# include <signal.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>

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
	struct s_nenv	*top_node;
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

typedef struct s_cmdtable
{
	char	*line;
	
}			t_cmdtable;

typedef struct s_minishell
{
	char		*line;
	int			c;
	int			out_fd;
	bool		is_builtin;
	int			redirect;
	int			input_fd;
	char		*name_file;
	char		*error_name_file;
	int			append;
	char		*commands[50];
	t_split		split;
	t_cmdtable	*cmdtable;
}				t_minishell;

int	g_ret_number;

t_nenv	*ft_node_format(t_nenv	*node);
void	ft_initialize_list(t_env *env_list);
void	ft_more_envp(t_env *env_list, char **env);
t_env	initialize_env(char **envp);

// FUNCTIONS
int 	check_args(int argc);
void	define_signals(void);

// BUILT-INS
void	ft_env(t_env *env_list);
void	ft_pwd(t_env *env_list);
void	ft_echo(char *cmd_line);

// UTILS
char	*skip_space(char *str);
void	init_split(t_minishell *mini);
void	ft_print_ppc(char  **splited, int aux);
int		count_pipe(t_minishell *mini, char *cmd, int i);
void	free_array(char **array);

// PARSER
void	split_cmd(t_minishell *mini, char *cmd, int i);
void	exec_commands(t_minishell *mini);
void	action(t_minishell *mini);
void	run_commands_aux(t_minishell *mini);

// EXEC
void	redirect_out(t_minishell *mini, int i);
void	redirect_in(t_minishell *mini, int c, char *aux);
void	simple_redir_out(t_minishell *mini, int i, int flags);
char	**re_redir(t_minishell *mini, char **file, int c);
char	*new_comman(int i, char **file);
void	read_until(char *file);
int		find_char(char *str, char wanted);

#endif
