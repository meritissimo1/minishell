/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:53:51 by marcrodr          #+#    #+#             */
/*   Updated: 2022/12/20 20:30:47 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	exec_process(t_minishell *mini, int input_fd, int out_fd)
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
			fd_handler(input_fd, out_fd);
			g_ret_number = 127;
			ft_execve_pipe(mini, 0, "");
			exit(g_ret_number);
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

void	ft_execve_pipe(t_minishell *mini, int i, char *command)
{
	if (mini->tokens[0])
		g_ret_number = execve(mini->tokens[0], &mini->tokens[0],
				mini->envp.env);
	while (mini->path && mini->path[i] != NULL)
	{
		command = ft_strdup(mini->path[i]);
		if (mini->tokens[0][0] == '|' && mini->tokens[1])
		{
			if (!mini->tokens[0][1])
				spacein_pipe(mini, 2, command);
			else
			{
				mini->tokens[0] = &mini->tokens[0][1];
				spacein_pipe(mini, 1, command);
			}
		}
		else
			spacein_pipe(mini, 1, command);
		i++;
	}
	execve_error(mini);
}

void	run_builtin(t_minishell *mini)
{
	int i = 0;
	if (!ft_strncmp(mini->tokens[0], "exit", 4))
		i++;//ft_exit(&mini->envp);
	if (!ft_strncmp(mini->tokens[0], "pwd", 3))
		ft_pwd(mini);
	if (!ft_strncmp(mini->tokens[0], "echo", 4))
		ft_echo(mini);
	if (!ft_strncmp(mini->tokens[0], "cd", 2))
		ft_cd(mini);
	if (!ft_strncmp(mini->tokens[0], "env", 3))
		ft_env(mini);
	if (!ft_strncmp(mini->tokens[0], "export", 6))
		i++;//ft_export(&mini->envp);
	if (!ft_strncmp(mini->tokens[0], "unset", 5))
		i++;//ft_unset(&mini->envp);
}
