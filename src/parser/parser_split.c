/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:19:20 by marcrodr          #+#    #+#             */
/*   Updated: 2022/10/17 09:39:35 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_cmd(t_minishell *mini, char *cmd, int i)
{
	init_split(mini);
	cmd = skip_space(cmd);
	int a = ft_strlen(cmd);
	(void)a;
	while (i < (int)ft_strlen(cmd)) 
	{
		if (mini->split.quote == 0 && (cmd[i] == D_QUOTE || cmd[i] == QUOTE))
			mini->split.quote = cmd[i];
		else
		{
			if (mini->split.quote == cmd[i])
				mini->split.quote = 0;
			else
				i = count_pipe(mini, cmd, i);
		}
		
		mini->split.len++;
		i++;
	}
	if (ft_strlen(cmd) > 0)
	{
		mini->commands[mini->split.qtt_comand] =
			ft_substr(cmd, mini->split.ini, i);
		mini->split.qtt_comand++;
	}
	free(cmd);
	mini->commands[mini->split.qtt_comand] = NULL;
	printf("the commands: [%s::%s::%s]\n", mini->commands[0], mini->commands[1], mini->commands[2]);
}
