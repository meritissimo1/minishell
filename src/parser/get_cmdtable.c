/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmdtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:28:51 by marcrodr          #+#    #+#             */
/*   Updated: 2022/10/10 11:31:11 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cmdtable(char *command_line, t_env envp)
{
	char	**cmd_split;
	(void)envp;
	if (command_line && command_line[0])
	{
		cmd_split = parser_split(command_line);		
	}
	printf("The Matriz - [%s %s]\n", cmd_split[0], cmd_split[1]);
}