/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:18:45 by marcrodr          #+#    #+#             */
/*   Updated: 2022/09/24 01:42:53 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	initialize_env(char **envp)
{
	t_env	env_list;
	char	**env;
	int		count;

	count = 0;
	ft_initialize_list(&env_list);
	env_list.top_node = ft_node_format(env_list.top_node);
	env = ft_split(envp[count++], 61);
	env_list.top_node->var =  env[0];
	env_list.top_node->content = env[1];
	env_list.size++;
	while (envp[count] != NULL)
	{
		ft_more_envp(&env_list, ft_split(envp[count++], 61));
	}
	//printf("OP count: %d\nOP envp: %lu\n", count, env_list.size);	//teste de contagem de variaveis de ambiente
	return(env_list);
}

void	ft_more_envp(t_env *env_list, char **env)
{
	t_nenv	*new;
	unsigned long int	ok;

	new = (t_nenv *)ft_calloc(sizeof(t_nenv), 1);
	new = ft_node_format(new);
	new = env_list->top_node;
	ok = 0;

	while (ok != env_list->size)
	{
		if (!new->next)
			new->next = ft_node_format(new);
		new = new->next;
		ok++;
	}
	new->var = env[0];
	new->content = env[1];
	//printf("var: %s ### content: %s \n", new->var, new->content);
	env_list->size++;
}

void	ft_initialize_list(t_env *env_list)
{
	env_list->size = 0;
	env_list->top_node = NULL;
}

t_nenv	*ft_node_format(t_nenv	*node)
{
	node = (t_nenv *)malloc(sizeof(t_nenv));
	node->next = NULL;
	if (!node)
		exit(0);
	return (node);
}