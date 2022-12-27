/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:36:08 by marcrodr          #+#    #+#             */
/*   Updated: 2022/12/26 19:00:08 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	there_home(t_minishell *mini);

int	ft_cd(t_minishell *mini)
{
	char	*tk_aux;
	bool	home;

	home = there_home(mini);
	if (mini->tokens[1])
		tk_aux = ft_strdup(mini->token.print);
	else
	{
		if (home == true)
			tk_aux = ft_strdup(mini->home);
		else
		{
			g_ret_number = 1;
			printf(ERROR_HOME);
			return (1);
		}
	}
	g_ret_number = chdir(tk_aux);
	if (g_ret_number == -1)
		printf("minishell: cd: %s: %s", mini->tokens[1], ERROR_DIR);
	free(tk_aux);
	return (0);
}

bool	there_home(t_minishell *mini)
{
	if(find_env(mini, "HOME"))
		return (true);
	else
		return (false);
}
