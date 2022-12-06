/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:20:37 by marcrodr          #+#    #+#             */
/*   Updated: 2022/12/06 10:29:57 by marcrodr         ###   ########.fr       */
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
	run_commands_aux(mini);
}

void	run_commands_aux(t_minishell *mini)
{
	 action(mini);
	 if (mini->commands[0][0] != '>')
	 {
		tokenizer(mini);
		if (mini->tokens[0])
			is_builtin(mini, mini->tokens[0]);
		if (mini->input_fd != -1)
			exec_process(mini, mini->input_fd, mini->out_fd);
		free_array(mini->tokens);
		free(mini->token.print);
		free(mini->token.exec);
	 }
	 if (mini->name_file)
	 	unlink(mini->name_file);	 
}

void	action(t_minishell *mini)
{
	mini->line = ft_strdup(mini->commands[mini->c]);
	if (mini->split.qtt_comand > 1)
		mini->c++;
	mini->error_name_file = NULL;
	while (mini->commands[mini->c] && mini->commands[mini->c][0] != '|')
	{
		redirect_out(mini, mini->c);
		redirect_in(mini, mini->c, NULL);
		mini->c++;
	}
	if (mini->error_name_file != NULL)
	{
		g_ret_number = 1;
		printf("minishell: %s: %s", mini->error_name_file, ERROR_DIR);
		free(mini->error_name_file);
	}
}

