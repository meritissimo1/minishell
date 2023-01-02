/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:35:56 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/31 22:36:34 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_minishell *mini)
{
	t_nenv	*aux;

	aux = mini->envp->top_node;
	while (aux)
	{
		ft_putstr_fd(aux->var, mini->out_fd);
		write(mini->out_fd, "=", 1);
		if (aux->content[0] != '`')
			ft_putstr_fd(aux->content, mini->out_fd);
		write(mini->out_fd, "\n", 1);
		aux = aux->next;
	}
	g_ret_number = 0;
}
