/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 02:01:31 by fmoreira          #+#    #+#             */
/*   Updated: 2022/09/24 02:13:09 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_env *env_list)
{
	t_nenv	*aux;
	int		count;

		aux = (t_nenv *)ft_calloc(sizeof(t_nenv), 1);
	aux = ft_node_format(aux);
	aux = env_list->top_node;
	count = 0;

	while (ft_strcmp(aux->var, "PWD"))
	{
		aux = aux->next;
	}

	if (!ft_strcmp(aux->var, "PWD"))
	{
		printf("%s\n", aux->content);
	}
	else
		printf("PWD doesnt exist\n");
}