/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:29:10 by marcrodr          #+#    #+#             */
/*   Updated: 2022/09/27 11:48:06 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	chech_operator(char *cmd_line, int i);
static int	check_quote(char *cmd_line, int *quote, int *apostrofhe, int *att);

int	parser_count(char *cmd_line)
{
	int	i;
	int	count;
	int	quote;
	int	apostrofhe;
	int	att;

	i = 0;
	count = 0;
	apostrofhe = 1;
	quote = 1;
	att = 0;
	while (cmd_line[i])
	{
		if((apostrofhe && quote && !att) && 
			!is_quote_apostrofhe(cmd_line[i])
			&& ((!ft_isspace(cmd_line[i])) && (i == 0 || 
			ft_isspace(cmd_line[i - 1]) || chech_operator(cmd_line, i)
			|| is_quote_apostrofhe(cmd_line[i - 1]))))
			count++;
		if (check_quote(cmd_line + i, &quote, &apostrofhe, &att))
			count++;
		i++;
	}
	if (!(apostrofhe && quote))
	{
		printf("Retorno parser_count: %d\n", count); // debbug
		return (-1);		
	}
		
	printf("Retorno parser_count: %d\n", count); // debug
	return (count);
}

static int	chech_operator(char *cmd_line, int i)
{
	if ((is_operator(cmd_line[i]) && !is_operator(cmd_line[i - 1]))
		|| (!is_operator(cmd_line[i]) && is_operator(cmd_line[i - 1])))
		return (1);
	return (0);
}

static int	check_quote(char *cmd_line, int *quote, int *apostrofhe, int *att)
{
	if (cmd_line[0] == '=' || ((*att) && ft_isspace(cmd_line[0])))
		(*att) = !(*att);
	if (cmd_line[0] == '\'')
	{
		if ((*quote))
		{
			(*apostrofhe) = !(*apostrofhe);
			if (!((*quote) && (*apostrofhe)) && !(*att))
				return (1);
		}
	}
	if  (cmd_line[0] == '\"')
	{
		if ((*apostrofhe))
		{
			(*quote) = !(*quote);
			if (!((*quote) && (*apostrofhe)) && !(*att))
				return (1);
		}
	}
	return (0);
}