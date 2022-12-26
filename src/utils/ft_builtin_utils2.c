/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:16:46 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/27 00:17:30 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell"

char	*ft_env_content(t_env *env_list, char *envp)
{
	t_nenv	*aux;

	aux = (t_nenv *)ft_calloc(sizeof(t_nenv), 1);
	aux = ft_node_format(aux);
	aux = env_list->top_node;
	while (ft_strcmp(aux->var, envp))
		aux = aux->next;
	if (!ft_strcmp(aux->var, envp))
		return(aux->content);
	else
		return(1); // ATENÇAO A ESTE RETORNO = $.
}