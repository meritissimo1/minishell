/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:19:20 by marcrodr          #+#    #+#             */
/*   Updated: 2022/10/05 11:45:07 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**parser_split(char *command_line)
{
	char	**parser;
	int		qtd;
	int		i;
	int		cmd_len;

	parser = NULL;
	qtd = parser_count(command_line);
	if (qtd <= 0)
		return (NULL);
	parser = (char **)malloc(sizeof(char *) * (qtd + 1));
	if (!parser)
		return (NULL);
	i = 0;
	printf("você digitou %d comandos\n", qtd);
	while (i < qtd)
	{
		command_line = ft_skip_space(command_line);
		cmd_len = parser_size(command_line);
		//parser = ft_substr(command_line, 0, cmd_len);
		command_line += cmd_len;
		i++;
		printf("Tamanho do %d° comando: %d\n",i, cmd_len);		
	}
	
	
	
	return (parser);	
}