/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:29:10 by marcrodr          #+#    #+#             */
/*   Updated: 2022/10/04 09:46:45 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser_count(char *cmd_line)
{
	int	i;
	int	count;
	int	quote;
	int	apostro;
	int	assign;

	i = 0;
	count = 0;
	apostro = 1;
	quote = 1;
	assign = 0;
	while (cmd_line[i])
	{
		if((apostro && quote && !assign) &&	!is_quote_apostro(cmd_line[i])
			&& ((!ft_isspace(cmd_line[i])) && (i == 0 ||
			ft_isspace(cmd_line[i - 1]) || chech_operator(cmd_line, i)
			|| is_quote_apostro(cmd_line[i - 1]))))
			count++;
		if (check_quote(cmd_line + i, &quote, &apostro, &assign))
			count++;
		i++;
	}
	if (!(apostro && quote))
		return (-1);
	return (count);
}

int	chech_operator(char *cmd_line, int i)
{
	if ((is_operator(cmd_line[i]) && !is_operator(cmd_line[i - 1]))
		|| (!is_operator(cmd_line[i]) && is_operator(cmd_line[i - 1])))
		return (1);
	return (0);
}

int	check_quote(char *cmd_line, int *quote, int *apostro, int *assign)
{
	if (cmd_line[0] == '=' || ((*assign) && ft_isspace(cmd_line[0])))
		(*assign) = !(*assign);
	if (cmd_line[0] == '\'')
	{
		if ((*quote))
		{
			(*apostro) = !(*apostro);
			if (!((*quote) && (*apostro)) && !(*assign))
				return (1);
		}
	}
	if  (cmd_line[0] == '\"')
	{
		if ((*apostro))
		{
			(*quote) = !(*quote);
			if (!((*quote) && (*apostro)) && !(*assign))
				return (1);
		}
	}
	return (0);
}