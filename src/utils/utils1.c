/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:21 by marcrodr          #+#    #+#             */
/*   Updated: 2022/12/29 20:46:20 by marcrodr         ###   ########.fr       */
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
	array = NULL;
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
	aux = mini->envp->top_node;
	len_env = ft_strlen(env);
	while (i <= (int)mini->envp->size)
	{
		len = ft_strlen(aux->var);
		if (!ft_strncmp(aux->var, env, len_env)
			&& len == len_env)
			return (aux->content);
		aux = aux->next;
	}
	return (0);
}

int	check_quote(t_minishell *mini, char c, char *aux, int nbr)
{
	if (mini->token.quote == 0 && (c == QUOTE || c == D_QUOTE))
		mini->token.quote = c;
	else
	{
		if (mini->token.quote == c)
			mini->token.quote = 0;
		else
		{
			aux[nbr] = c;
			nbr++;
		}
	}
	return (nbr);
}

void	check_flags(t_minishell *mini, char *in, int i, int c)
{
	char	*aux;

	mini->token.quote = 0;
	aux = ft_strtrim(in, " ");
	mini->flag = false;
	if (in[0] == '-' && in[1] == 'n')
	{
		mini->flag = true;
		i += 2;
	}
	while (in[i] == ' ')
		i++;
	while (in[i])
	{
		c = check_quote(mini, in[i], aux, c);
		i++;
	}
	aux[c] = '\0';
	free(mini->token.print);
	mini->token.print = aux;
}