/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:54:08 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/29 16:44:32 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_nenv	*ft_find_node(t_env *env_list, char *envp)
{
	t_nenv	*aux;
	unsigned long int	i;

	i = 0;
	aux = env_list->top_node;
	while (ft_strcmp(aux->var, envp) && i++ < env_list->size)
	{
		if (!aux->next)
			break ;
		aux = aux->next;
	}
	if (!ft_strcmp(aux->var, envp))
		return(aux);
	else
	{
		aux = NULL;
		return(aux);
	}
}
