/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:53:51 by marcrodr          #+#    #+#             */
/*   Updated: 2022/11/28 20:46:56 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	exec_process(t_minishell *mini, int input_fd, int out_fd)
{
	pid_t	pid;
	(void)input_fd;
	(void)out_fd;
  
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
			fd_handler(input_fd, out_fd);
			g_ret_number = 127;
				
								
		}
		else
			waitpid(pid, &g_ret_number, WUNTRACED);
		if (WIFEXITED(g_ret_number))
			g_ret_number = WEXITSTATUS(g_ret_number);
	}	
}

int	fd_handler(int input_fd, int out_fd)
{
	if (input_fd != 0)
	{
		dup2(input_fd, 0);
		close(input_fd);
	}
	if (out_fd != 1)
	{
		dup2(out_fd, 1);
		close(out_fd);
	}
	return (0);
}

void	run_builtin(t_minishell *mini)
{
	int i = 0;
	if (!ft_strncmp(mini->tokens[0], "exit", 4))
		i++;//ft_exit(&mini->envp);
	if (!ft_strncmp(mini->tokens[0], "pwd", 3))
		i++;//ft_pwd(&mini->envp);
	if (!ft_strncmp(mini->tokens[0], "echo", 4))
		ft_echo(mini);
	if (!ft_strncmp(mini->tokens[0], "cd", 2))
		i++;//ft_cd(&mini->envp);
	if (!ft_strncmp(mini->tokens[0], "env", 3))
		i++;//ft_env(&mini->envp);
	if (!ft_strncmp(mini->tokens[0], "export", 6))
		i++;//ft_export(&mini->envp);
	if (!ft_strncmp(mini->tokens[0], "unset", 5))
		i++;//ft_unset(&mini->envp);
}
