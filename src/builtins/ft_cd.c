/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:25:01 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/31 19:09:42 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	there_home(t_minishell *mini);

void	ft_cd(t_minishell *mini)

{
	char	*tk_aux;
	bool	home;

	tk_aux = NULL;
	home = there_home(mini);
	if (mini->tokens[1])
		tk_aux = ft_strdup(mini->token.print);
	else
	{
		if (home == false)
		{
			g_ret_number = 1;
			printf(ERROR_HOME);
		}
		else
			tk_aux = ft_strdup(mini->home);
	}
	g_ret_number = chdir(tk_aux);
	if (g_ret_number == -1)
		printf("minishell: cd: %s: %s", mini->tokens[1], ERROR_DIR);
	else
		ft_cd_att(mini);
	free(tk_aux);
	//return (0);
}

bool	there_home(t_minishell *mini)
{
	if(find_env(mini, "HOME"))
		return (true);
	else
		return (false);
}


void	ft_cd_att(t_minishell *mini)
{
	t_nenv	*pwd_aux;
	t_nenv	*old_pwd_aux;
	char	*to_join;
	char	**to_split;
	
	old_pwd_aux = ft_find_node(mini->envp, "OLDPWD");
	to_join = ft_strjoin("PWD", "=");
	to_join = ft_strjoin(to_join, old_pwd_aux->content);
	to_split = ft_split(to_join, 61);
	if (!ft_find_node(mini->envp, "PWD"))
	{
		pwd_aux = old_pwd_aux;
		ft_one_more_envp(mini->envp->top_node, to_split, 0);
		mini->envp->size++;
	}
	else
		pwd_aux = ft_find_node(mini->envp, "PWD");
	old_pwd_aux->content = pwd_aux->content;
	pwd_aux->content = ft_pwd(mini);
	free_kenji(to_split);
	free(to_join);
}
