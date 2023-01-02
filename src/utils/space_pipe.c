/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:51:46 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/01 22:41:09 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	spacein_pipe(t_minishell *mini, int i, char *command)
{
	char	*aux;

	if (ft_strlen(mini->token.print) && mini->tokens[i]
		&& (mini->tokens[i][0] == QUOTE || mini->tokens[i][0] == D_QUOTE)
			&& ft_strncmp(mini->tokens[i - 1], "sed", 3))
	{
		aux = ft_strtrim(mini->token.print, D_QUOTE_S);
		free_token(&mini->tokens[i + 1]);
	}
	else
		aux = ft_strtrim(mini->tokens[i], D_QUOTE_S);
	free(mini->tokens[i]);
	mini->tokens[i] = aux;
	command = ft_strjoin(command, mini->tokens[i - 1]);
	g_ret_number = execve(command, &mini->tokens[i - 1], mini->envp->env);
	free(command);
}

void	free_token(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
}

void	execve_error(t_minishell *mini)
{
	g_ret_number = 127;
	if (mini->tokens[0][0] != '|')
		printf("minishell: %s: %s", mini->tokens[0], ERROR_CMD);
	else if (mini->tokens[1])
		printf("minishell: %s: %s", mini->tokens[1], ERROR_CMD);
}
