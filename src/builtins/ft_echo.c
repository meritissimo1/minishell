/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:07:02 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/26 16:01:54 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
char	**ft_token_rawline(char **tokens, char *rawline);


void	ft_echo(t_minishell *mini)
{
	//printf("%s\n", mini->line);
	ft_token_rawline(mini->tokens, mini->rawline);
	/*
	if (ft_strcmp(mini->tokens[1], "-n"))
		ft_print_ppc(mini->tokens, mini->out_fd, 0);
	else
		ft_print_ppc(mini->tokens, mini->out_fd, 1);
	*/
}

size_t	ft_count_echo(char **tokens, char *rawline)
{
	size_t i;
	char	*raw_aux;

	raw_aux = ft_strdup(rawline);
	(void)tokens;
	i = 5;
	while (raw_aux[i])
	{
		//printf("dentro do count %zu\n", i);
		if (raw_aux[i] == D_QUOTE)
		{
			raw_aux++;
			printf("dentro do d_quote %zu\n", i);
			while (raw_aux[i] != D_QUOTE)
			{
				printf("dentro do d_quote x2 %zu\n", i);
				i++;
				if (!rawline[i])
				{
					printf("\" not found\n");
					break ;
				}
			}
			if (raw_aux[i] == D_QUOTE)
				raw_aux++;
		}
		else if (raw_aux[i] == QUOTE)
		{
			while (raw_aux[i++] != QUOTE)
			{
				if (raw_aux[i])
					printf("\' not found\n");
			}
		}
		if (raw_aux[i] == 32)
			raw_aux++;
		printf("%s\n", raw_aux);
	}
	return (i - 5);
}
char	**ft_token_rawline(char **tokens, char *rawline) //precisa por a verificaçao do "$ENV"
{
	char	**taux;
	int		i;
	int		j;
	int		k;
	//int 	helper;

	i = ft_count_echo(tokens, rawline);
	printf("count echo %d\n", i);
	taux = malloc((i + 1) * sizeof(char *));
	i = 4;
	j = 0;

	//printf("%s\n\n", rawline + 5);
	while (rawline[++i])
	{
		k = 0;
		printf("aopa %d\n", i);
		if (rawline[i] == D_QUOTE)
		{
			while (rawline[++i] != D_QUOTE || rawline[i])
			{
				printf("aopa %d %c\n", i, rawline[i]);
				taux[j][k] = rawline[i];
				k++;
			}
			taux[j][k] = 0;
			j++;
			k = 0;
			if (!rawline)
				printf("problem!\n");
		}
		while (rawline[i] != (char)32) // while precisa terminar de criar seu token
		{
			printf("aopa %d\n", i);
			taux[j][k++] = rawline[i++];
			if (taux[j][k])
				break ;
		}
		printf("linha 100 %d\n", i);
		taux[j][k] = rawline[i];
		printf("%s\n", taux[j]);
	}
	//printf("%s\n", taux);
	(void)tokens;
	return (taux);
}