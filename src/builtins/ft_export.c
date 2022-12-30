/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:46:04 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/30 19:01:44 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	ft_export(t_minishell *mini)
{
	t_nenv	*aux;
	char	**split_aux;
	int		len;

	len = (int)ft_strlen(mini->token.print);
	if(!len)
		return ;
	if (find_char(mini->token.print, '=') == len)
		mini->token.print = ft_strjoin(mini->token.print, "=");
	split_aux = ft_split(mini->token.print, 61);
	if (!split_aux[1])
		return ;
	aux = ft_find_node(mini->envp, split_aux[0]);
	if (!aux)
	{
		ft_one_more_envp(mini->envp->top_node, split_aux, 0);
		mini->envp->size++;
	}
	else if (!ft_strcmp(aux->var, split_aux[0]))
		aux->content = ft_strdup(split_aux[1]);
	free_kenji(split_aux);
}
