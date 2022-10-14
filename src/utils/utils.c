/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:38:25 by marcrodr          #+#    #+#             */
/*   Updated: 2022/10/14 17:20:03 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*skip_space(char *str)
{
	char	*aux;

	aux = ft_strtrim(str, " ");
	str = aux;
	return (str);
}

void	ft_print_ppc(char  **splited, int aux)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		printf("%s", splited[i++]);
		if (aux == 0)
			printf(" ");
		if (aux == 1 && ft_strcmp(splited[i], "\n"))
			break;
	}
	if (aux == 0)
		printf("\n");
}

void	init_split(t_minishell *mini)
{
	mini->split.qtt_comand = 0;
	mini->split.ini = 0;
	mini->split.len = 0;
	mini->split.qtt_pipe = 0;
	mini->split.quote = 0;
}

int	count_pipe(t_minishell *mini, char *cmd, int i)
{
	if (cmd[i] == '|' || cmd[i] == '<' || cmd[i] == '>')
	{
		if (cmd[i] == '|' && mini->split.quote == 0)
			mini->split.qtt_pipe++;
		if (mini->split.quote == 0 && i > 0 && mini->split.len > 0)
		{
			mini->commands[mini->split.qtt_comand] = ft_substr(cmd,
					mini->split.ini, mini->split.len);
			mini->split.ini = i;
			mini->split.len = 0;
			mini->split.qtt_comand++;
			if (cmd[i] == '>')
				mini->redirect = 1;
			else
				mini->redirect = 0;
			if (cmd[i] == cmd[i + 1])
			{
				i++;
				mini->split.len = 1;
			}
			printf("Tem um separador %c nessa posicao -> %d e o n° de pipes é %d\n", cmd[mini->split.ini] , mini->split.ini, mini->split.qtt_pipe);			
		}
	}
	return (i);
}
