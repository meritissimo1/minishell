/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmdtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:28:51 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/01 22:33:51 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_pipe(t_minishell *mini, char *cmd, int i)
{
	if (cmd[i] == '|' || cmd[i] == '<' || cmd[i] == '>')
	{
		if (cmd[i] == '|' && mini->split.quote == 0)
			mini->split.qtt_pipe++;
		if (mini->split.quote == 0 && i > 0 && mini->split.len > 0)
		{
			mini->commands[mini->split.qtt_comand] = ft_substr(cmd,
					mini->split.ini, mini->split.len);
			mini->split.ini = i;
			mini->split.len = 0;
			mini->split.qtt_comand++;
			if (cmd[i] == '>')
				mini->redirect = 1;
			else
				mini->redirect = 0;
			if (cmd[i] == cmd[i + 1])
			{
				i++;
				mini->split.len = 1;
			}
		}
	}
	return (i);
}
