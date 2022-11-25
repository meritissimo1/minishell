/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 02:01:31 by fmoreira          #+#    #+#             */
/*   Updated: 2022/11/23 13:03:02 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_minishell *mini)
{
	t_nenv	*aux;
//	int		count; // set but not used

	aux = (t_nenv *)ft_calloc(sizeof(t_nenv), 1);
	aux = ft_node_format(aux);
	aux = mini->envp.top_node;
//	count = 0;

	while (ft_strcmp(aux->var, "PWD"))
	{
		aux = aux->next;
	}

	if (!ft_strcmp(aux->var, "PWD"))
	{
		printf("%s\n", aux->content);
	}
	else
		printf("PWD doesn't exist\n");
}