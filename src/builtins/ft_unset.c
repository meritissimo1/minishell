/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:11:38 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/29 20:49:31 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_nenv	*ft_find_prev_node(t_env *env_list, char *envp);

void	ft_unset(t_minishell *mini)
{
	t_nenv	*aux;
	t_nenv	*to_free;

	to_free = NULL;
	aux = ft_find_prev_node(mini->envp, mini->token.print);
	if (!ft_strcmp(mini->envp->top_node->var, mini->token.print))
	{
		mini->envp->top_node = mini->envp->top_node->next;
		if (aux->var)
			free(aux->var);
		if (aux->content)
			free(aux->content);
		free(aux);
	}
	else if (!ft_strcmp(aux->next->var, mini->token.print))
	{
		to_free = aux->next;
		aux->next = to_free->next;
		if (to_free->var)
			free(to_free->var);
		if (to_free->content)
			free(to_free->content);
		free(to_free);
	}		
}

t_nenv	*ft_find_prev_node(t_env *env_list, char *envp)
{
	t_nenv	*aux;
	unsigned long int	i;

	i = 0;
	aux = env_list->top_node;
	if (!ft_strcmp(aux->var, envp))
		return(aux);
	while (ft_strcmp(aux->next->var, envp) && i++ < env_list->size)
	{
		if (!aux->next)
			break ;
		aux = aux->next;
	}
	if (!ft_strcmp(aux->next->var, envp))
		return(aux);
	else
	{
		aux = NULL;
		return(aux);
	}
}