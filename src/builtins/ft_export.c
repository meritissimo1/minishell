/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:46:04 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/28 23:57:52 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_minishell *mini)
{
	t_nenv	*aux;
	char	**split_aux;

	split_aux = ft_split(mini->token.print, 61);
	aux = ft_env_node(&mini->envp, split_aux[0]);
	printf("sim2\n");
	//printf("var: %s\ncontent: %s\n", aux->var, aux->content);
	if (!aux)
	{
		printf("split 0: %s\n split 1: %s\n", split_aux[0], split_aux[1]);
		ft_more_envp(&mini->envp, split_aux);
	}
	else if (split_aux[1])
	{
		printf("var: %s\ncontent: %s\n", aux->var, aux->content);
		aux->content = split_aux[1];
	}
	//printf("var: %s\ncontent: %s\n", aux->var, aux->content);
	//printf("_var: %s\n_content: %s\n", aux->next->var, aux->next->content);
}
