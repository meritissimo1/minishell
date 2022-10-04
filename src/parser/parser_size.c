/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:25:25 by marcrodr          #+#    #+#             */
/*   Updated: 2022/10/04 09:47:24 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int parser_size(char *cmd_line)
{
	int	i;
	int	quote;
	int	apostro;
	int	assign;
	int	token;

	i = 0;
	token = 0;
	apostro = 1;
	quote = 1;
	assign = 0;
	while (cmd_line[i])
	{
		if((apostro && quote && !assign) &&	!is_quote_apostro(cmd_line[i])
			&& ((ft_isspace(cmd_line[i])) || (i == 0 ||
			ft_isspace(cmd_line[i]) || chech_operator(cmd_line, i)
			|| is_quote_apostro(cmd_line[i - 1]))))
			token = !token;
		if (check_quote(cmd_line + i, &quote, &apostro, &assign))
			token = !token;
		if (!token && !assign)
			return (i);
		i++;
	}
	return (i);
}
