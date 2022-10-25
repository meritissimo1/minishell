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
