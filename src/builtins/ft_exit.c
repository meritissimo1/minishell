/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:43:35 by marcrodr          #+#    #+#             */
/*   Updated: 2022/12/29 11:46:02 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_exit(t_minishell *mini)
{
	free_commands(mini->commands);
	if (mini->path)
		free_array(mini->path);
	free_linkedlist(mini);
	free(mini->home);
	free(mini->envp);
	printf("exit\n");
	exit(0);
}
