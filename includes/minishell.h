/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:04:40 by marcrodr          #+#    #+#             */
/*   Updated: 2022/10/14 16:52:36 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H 

# include "libft.h"
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

# define D_QUOTE '\"'
# define QUOTE '\''
# define D_QUOTE_S "\""
# define QUOTE_S "\'"

# define PROMPT "#> "

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

typedef struct s_minishell
{
	int		redirect;
	char	*commands[50];
	t_split	split;
}			t_minishell;

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

// PARSER
void	split_cmd(t_minishell *mini, char *cmd, int i);







#endif