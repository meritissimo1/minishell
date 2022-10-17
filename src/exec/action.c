/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:30:02 by marcrodr          #+#    #+#             */
/*   Updated: 2022/10/17 12:11:28 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(t_minishell *mini, char *cmd)
{
	//action(mini);
	if (mini->commands[0][0] != '>')
	{
		tokenizer(mini);
	}
}

void	action(t_minishell *mini)
{
	mini->cmdtable->line = ft_strdup(mini->commands[mini->c]);
	if (mini->split.qtt_comand > 1)
		mini->c++;
	mini->cmdtable->error_name_file = NULL;
	while (mini->commands[mini->c] && mini->commands[mini->c][0] != '|')
	{
		// em obra
	}
		
}