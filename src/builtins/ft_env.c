/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:35:56 by fmoreira          #+#    #+#             */
/*   Updated: 2022/09/24 02:04:53 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_env *env_list)
{
	t_nenv	*aux;

	aux = (t_nenv *)ft_calloc(sizeof(t_nenv), 1);
	aux = ft_node_format(aux);
	aux = env_list->top_node;

	while (aux->next)
	{
		printf("%s=%s\n", aux->var, aux->content);
		aux = aux->next;
	}
}