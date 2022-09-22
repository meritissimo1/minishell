/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:04:40 by marcrodr          #+#    #+#             */
/*   Updated: 2022/09/22 09:21:52 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H 

# include "libft.h"
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

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


t_nenv	*ft_node_format(t_nenv	*node);
void	ft_initialize_list(t_env *env_list);
void	ft_more_envp(t_env *env_list, char **env);
t_env	initialize_env(char **envp);


// FUNCTIONS
int 	check_args(int argc);
void	define_signals(void);



#endif