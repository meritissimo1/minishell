/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:55:03 by marcrodr          #+#    #+#             */
/*   Updated: 2022/11/01 09:15:10 by marcrodr         ###   ########.fr       */
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
			mini->out_fd = open(file, flags | O_APPEND, 0777);
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
	mini->out_fd = open(file, flags | O_TRUNC, 0777);	
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



/*
void	redirect_out(t_struct *mini, int j)
{
	int		flags;
	char	*file;

	flags = O_WRONLY | O_CREAT;
	j = mini->c;
	if (mini->commands[j] && mini->commands[j][0] == '>')
	{
		if (mini->commands[j] && mini->commands[j][1] == '>')
		{
			file = ft_strtrim(&mini->commands[j][2], " ");
			mini->out_fd = open(file, flags | O_APPEND, 0777);
			free (file);
		}
		else
			simple_redir_out(mini, j, flags);
		mini->last_redir = 1;
		if (mini->split.n_comand == 1)
			free(mini->line);
	}
}

void	simple_redir_out(t_struct *mini, int j, int flags)
{
	char	*aux;
	char	*file;

	aux = ft_strtrim(&mini->commands[j][1], " ");
	file = ft_substr(aux, 0, find_char(aux, ' '));
	mini->out_fd = open(file, flags | O_TRUNC, 0777);
	free (aux);
	free (file);
}

int	find_char(char *string, char needle)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == needle)
			return (i);
		i++;
	}
	return (i);
}
*/
