/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:07:02 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/16 20:38:12 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_minishell *mini)
{
	if (mini->tokens == NULL)
		printf("\n");
	else
	{
		if (ft_strcmp(mini->tokens[1], "-n"))
			ft_print_ppc(mini->tokens, mini->out_fd, 0);
		else
			ft_print_ppc(mini->tokens, mini->out_fd, 1);
	}
}
