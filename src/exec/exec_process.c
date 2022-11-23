/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:53:51 by marcrodr          #+#    #+#             */
/*   Updated: 2022/11/22 17:26:05 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_process(t_minishell *mini, int in_fd, int out_fd)
{
	pid_t	pid;
	if (mini->is_builtin && mini->tokens[0])
		run_builtin(mini);
	else
	{
		pid = fork();
		run_signals(2);
		if (pid < 0)
		{
			printf("Fork error\n");
			g_ret_number = 127;
		}
		else if (pid == 0)
		{
			
		}
	}	
}

void	run_builtin(t_minishell *mini)
{
	if (!ft_strncmp(mini->tokens[0], "exit", 4))
		ft_exit(mini);
	if (!ft_strncmp(mini->tokens[0], "pwd", 3))
		ft_pwd(mini);
	if (!ft_strncmp(mini->tokens[0], "echo", 4))
		ft_echo(mini);
	if (!ft_strncmp(mini->tokens[0], "cd", 2))
		ft_cd(mini);
	if (!ft_strncmp(mini->tokens[0], "env", 3))
		ft_env(mini);
	if (!ft_strncmp(mini->tokens[0], "export", 6))
		ft_export(mini);
	if (!ft_strncmp(mini->tokens[0], "unset", 5))
		ft_unset(mini);
}
