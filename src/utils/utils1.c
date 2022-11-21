/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:21 by marcrodr          #+#    #+#             */
/*   Updated: 2022/11/18 16:47:33 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

int	tokenizer_find_char(char *string, char needle)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == needle || string[i] == D_QUOTE || string[i] == QUOTE)
			return (i);
		if (string[i] == '?')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*find_env(t_minishell *mini, char *env)
{
	int		i;
	int		len;
	int		len_env;
	t_nenv	*aux;

	i = 0;
	aux = mini->envp.top_node;
	mini->envp.index = 0;
	len_env = ft_strlen(env);
	while (aux->next && i < (int)mini->envp.size)
	{
		len = ft_strlen(aux->var);
		if (!ft_strncmp(aux->var, env, len_env)
			&& len == len_env)
		{
			mini->envp.index = i;
			return (aux->content);
		}
		aux = aux->next;
	}
	return (0);
}