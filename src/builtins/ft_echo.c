/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:07:02 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/24 02:18:01 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_minishell *mini)
{
	if (ft_strcmp(mini->tokens[1], "-n"))
		ft_print_ppc(mini->tokens, mini->out_fd, 0);
	else
		ft_print_ppc(mini->tokens, mini->out_fd, 1);
}

char	*ft_token_rawline(char **tokens, char *rawline) //precisa por a verificaçao do "$ENV"
{
	char	**taux;
	char	*aux;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	while (rawline[++i])
	{
		if (rawline[i] == D_QUOTE && j++)
		{
			while (rawline[++i] != D_QUOTE || rawline[i])
			{
				taux[j][k++] = rawline[i]
			}
			taux[j][k] = NULL;
			k = 0;
			if (!rawline)
				printf("problem!\n");
		}
		while (rawline[i] != (char)32) // while precisa terminar de criar seu token
		{
			taux[j][k++] = rawline[i++];
		
	}
}