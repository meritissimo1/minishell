/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:07:02 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/12 15:54:38 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// quero criar uma funçao que percorra o readline (rawline) procurando as paravras separadas do **tokens, caso estejam todas ok
// a funçao vai printar caso elas sejam equivalentes o echo funciona corretamente.
void	ft_echo(t_minishell *mini)
{
	//printf("socorro deus");
	ft_print_ppc(mini->tokens, 0);
}
/*
int	ft_echo_authn(char *rawline, char *words)
{
	char	find_quotes;
	int		i;

}

{
	char	**splited;

	splited = ft_split(mini->line, 32);
	ft_print_ppc(splited, 0);  // printa o comando ***precisa ser reavalidade de sua utilidade***
	if (ft_strcmp(splited[2], "-n"))
		ft_print_ppc(splited + 2, 0);
	else
		ft_print_ppc(splited, 1);
}
*/