/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:18:45 by marcrodr          #+#    #+#             */
/*   Updated: 2022/12/29 23:57:56 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_initialize_env(char **envp)
{
	t_env	*envp_list;
	
	envp_list = (t_env *)ft_calloc(sizeof(t_env), 1); 	
	ft_initialize_list(envp_list);
	envp_list->env = envp;
	envp_list->top_node = ft_node_format(envp_list, envp, 0, 0);
	return(envp_list);
}

void	ft_more_envp(t_nenv *node, char **env, int ok)
{
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

void	ft_initialize_list(t_env *env_list)
{
	env_list->size = 0;
	env_list->top_node = NULL;
}

t_nenv	*first_node(t_nenv *node, t_nenv *head, char **env, t_env *env_list)
{
	node = (t_nenv *)ft_calloc(sizeof(t_nenv), 1);
	node->var = ft_strdup(env[0]);
	node->content = ft_strdup(env[1]);
	head = node;
	node->next = NULL;
	env_list->size++;
	return (head);
}

t_nenv	*ft_node_format(t_env *env_list, char **envp, int count, int ok)
{
	t_nenv	*head;
	t_nenv	*node;
	char	**env;
	
	node = env_list->top_node;
	while (envp[count] != NULL)
	{
		env = ft_split_by_idx(envp[count], ft_find_idx(envp[count], '='));
		ok = 0;
		if ( env_list->size == 0)
			head = first_node(node, head, env, env_list);
		else
		{			
			if (env[1] == NULL)
			{
				env[1] = ft_strdup("");
				ok = 1;				
			}				
			ft_more_envp(head, env, ok);
			env_list->size++;
		}
		ft_free_split(env);		
		count++;			
	}
	return (head);
}
