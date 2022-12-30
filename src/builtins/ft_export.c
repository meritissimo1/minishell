/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:46:04 by fmoreira          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/30 21:00:08 by fmoreira         ###   ########.fr       */
=======
/*   Updated: 2022/12/29 20:43:49 by marcrodr         ###   ########.fr       */
>>>>>>> 00a3a03d90aea64f1be3c57900f1d52cc2adb49d
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_minishell *mini)
{
	t_nenv	*aux;
	char	**split_aux;

	if(!ft_strlen(mini->token.print))
		return ;
	split_aux = ft_split(mini->token.print, 61);
	aux = ft_find_node(mini->envp, split_aux[0]);
	if (!aux)
	{
		ft_more_envp(mini->envp->top_node, split_aux, 0);
		mini->envp->size++;
	}
	else if (!ft_strcmp(aux->var, split_aux[0]))
		aux->content = split_aux[1];
	free_array(split_aux);
}
