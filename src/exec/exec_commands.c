/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:20:37 by marcrodr          #+#    #+#             */
/*   Updated: 2022/10/27 10:50:58 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_commands(t_minishell *mini)
{
	int	i;
	int fd[2];

	i = 0;
	mini->redirect = 0;
	mini->c = 0;
	while (i < mini->split.qtt_pipe)
	{
		if (pipe(fd) < 0)
		{
			printf("Pipe Error\n");
			g_ret_number = 127;
		}
		mini->out_fd = fd[1];
		run_commands_aux(mini);		
		close(mini->out_fd);
		i++;
	}

}

void	run_commands_aux(t_minishell *mini)
{
	 action(mini);
}

void	action(t_minishell *mini)
{
	mini->line = ft_strdup(mini->commands[mini->c]);
	if (mini->split.qtt_comand > 1)
		mini->c++;
	mini->cmdtable->error_name_file = NULL;
	while (mini->commands[mini->c] && mini->commands[mini->c][0] != '|')
	{
		redirect_out(mini, mini->c);
		redirect_in(mini, mini->c, NULL);
		mini->c++;
	}
}

