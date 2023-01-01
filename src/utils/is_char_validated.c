/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char_validated.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:37:22 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/01 22:40:06 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quote_apostro(char c)
{
	if (c == '\"' || c == '\'')
		return (1);
	return (0);
}

int	is_operator(char c)
{
	if (c == '>' || c == '<'
		|| c == '&' || c == '|' )
		return (1);
	return (0);
}

void	free_linkedlist(t_minishell *mini)
{
	t_nenv	*aux;
	t_nenv	*next;
	int		i;

	i = 0;
	aux = mini->envp->top_node;
	while (aux)
	{
		next = aux->next;
		if (aux->var)
			free(aux->var);
		if (aux->content)
			free(aux->content);
		free(aux);
		aux = next;
		i++;
	}
	free(mini->envp);
	mini->envp = NULL;
}
