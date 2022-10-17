/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:20:37 by marcrodr          #+#    #+#             */
/*   Updated: 2022/10/17 11:31:23 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_commands(t_minishell *mini, char *cmd);
{
	int	i;
	int fd[2];

	i = 0;
	mini->redirect = 0;
	mini->c = 0;
	while (i < mini->split.qtt_pipe)
	{
		// exec pipe
		exec(mini, cmd);
		
	}	
}
