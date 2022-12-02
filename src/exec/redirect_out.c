/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:55:03 by marcrodr          #+#    #+#             */
/*   Updated: 2022/12/02 19:11:17 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	redirect_out(t_minishell *mini, int i)
{
	int		flags;
	char	*file;
	flags = O_WRONLY | O_CREAT;
	i = mini->c;
	if (mini->commands[i] && mini->commands[i][0] == '>')
	{
		if (mini->commands[i] && mini->commands[i][1] == '>')
		{
			file = ft_strtrim(&mini->commands[i][2], " ");
			mini->out_fd = open(file, flags | O_APPEND, 0644);
			printf("well well whats here fd:%d\nfile: %s\n", mini->out_fd, file);
			free(file);
		}
		else
			simple_redir_out(mini, i, flags);
	}
			
}

void	simple_redir_out(t_minishell *mini, int i, int flags)
{
	char	*aux;
	char	*file;

	aux = ft_strtrim(&mini->commands[i][1], " ");
	file = ft_substr(aux, 0, find_char(aux, ' '));
	mini->out_fd = open(file, flags | O_TRUNC, 0644);	
	free(aux);
	free(file);
}


int	find_char(char *str, char wanted)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == wanted)
			return (i);
		i++;
	}
	return (i);
}
