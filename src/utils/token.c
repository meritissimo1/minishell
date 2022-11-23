/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:06:09 by marcrodr          #+#    #+#             */
/*   Updated: 2022/11/21 15:54:26 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*init_tk()
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->end = NULL;
	token->new = NULL;
	token->exec = NULL;
	token->print = NULL;
	token->quote = '\0';
	token->i = 0;
	token->init = 0;
	token->len = 1;	
	token->posic = 0;
	return (token);	
}

void	get_home_sign(t_minishell *mini, t_token *tk)
{
	char	*extend;

	tk->new = ft_substr(mini->line, tk->init, tk->len - 1);
	tk->end = ft_strjoin(tk->end, tk->new);
	free(tk->new);
	extend = "home"; //mini->home;
	tk->end = ft_strjoin(tk->end, extend);
	tk->i++;
	tk->len = 1;
	tk->init = tk->i;
}

void	get_dollar_sign(t_minishell *mini, t_token *tk)
{
	char	*extend;
	char	*n_env;

	tk->new = ft_substr(mini->line, tk->init, tk->len - 1);
	tk->end = ft_strjoin(tk->end, tk->new);
	free(tk->new);
	tk->posic = tokenizer_find_char(&mini->line[tk->i + 1], ' ');
	n_env = ft_substr(mini->line, tk->i + 1, tk->posic);
	if (mini->line[tk->i + 1] != '?' && find_env(mini, n_env))
		extend = ft_strdup(find_env(mini, n_env));
	else if (mini->line[tk->i + 1] == '?')
		extend = ft_itoa(g_ret_number);
	else
		extend = NULL;
	if (extend)
		tk->end = ft_strjoin(tk->end, extend);
	free(extend);
	tk->i += ft_strlen(n_env) + 1;
	free(n_env);
	tk->len = 1;
	tk->init = tk->i;
}