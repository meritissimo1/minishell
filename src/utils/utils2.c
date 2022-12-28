/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:54:08 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/28 23:46:50 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_nenv	*ft_env_node(t_env *env_list, char *envp)
{
	t_nenv	*aux;
	unsigned long int	i;

	i = 0;
	aux = (t_nenv *)ft_calloc(sizeof(t_nenv), 1);
	aux = ft_node_format(aux);
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
//		ft_more_envp(env_list, ft_split(envp, 61));
		return(aux);
	}
}
