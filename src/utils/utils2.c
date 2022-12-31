/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:54:08 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/31 01:12:02 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_nenv	*ft_find_node(t_env *env_list, char *envp)
{
	t_nenv	*aux;
	unsigned long int	i;

	i = 1;
	aux = env_list->top_node;
	if(!ft_strlen(envp))
		return (NULL);
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

void	ft_one_more_envp(t_nenv *node, char **env, int ok)
{
	if (env[1] == NULL)
	{
		env[1] = ft_strdup("");
		ok = 1;
	}
	while (node->next)
		node = node->next;
	node->next = (t_nenv *)ft_calloc(sizeof(t_nenv), 1);
	node = node->next;
	node->var = ft_strdup(env[0]);
	if (!ok)
		node->content = ft_strdup(env[1]);
	else
		node->content = env[1];
	node->next = NULL;
}