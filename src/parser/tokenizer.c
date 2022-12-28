/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:51:21 by marcrodr          #+#    #+#             */
/*   Updated: 2022/12/26 17:21:58 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenizer(t_minishell *mini)
{
	t_token *tk;

    tk = init_tk();
	mini->token.quote = 0;
	if (mini->line)
	{
		while((int)ft_strlen(mini->line) > tk->i)
		{
			if (mini->token.quote == 0 && (mini->line[tk->i] == QUOTE))
				mini->token.quote = mini->line[tk->i];
			else
			{
				if (mini->token.quote == mini->line[tk->i])
					mini->token.quote = 0;
				if (mini->line[tk->i] == '~' && mini->token.quote == 0)
					get_home_sign(mini, tk);
				else if (mini->line[tk->i] == '$' && mini->token.quote == 0)
					get_dollar_sign(mini, tk);
			}
			tk->i++;
			tk->len++;
		}
		finish_tokenizer(mini, tk);
	}
}
