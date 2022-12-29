/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:07:02 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/28 11:40:52 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_echo(t_minishell *mini, int n);
void	print_echo(t_minishell *mini, char *mini_tokens_i);

void	ft_echo(t_minishell *mini)
{
	init_echo(mini, 0);
	if (mini->tokens[1])
	{
		print_echo(mini, mini->token.print);
		if (!mini->flag)
			ft_putstr_fd("\n", mini->out_fd);
	}
	else
		ft_putstr_fd("\n", mini->out_fd);
}

int	init_echo(t_minishell *mini, int n)
{
	if (mini->tokens[0][0] != '|')
		n = 1;
	else
		n = 2;
	return (n);
}

void	print_echo(t_minishell *mini, char *mini_tokens_i)
{
	if (!ft_strncmp(mini_tokens_i, "$?", 2))
		ft_putnbr_fd(g_ret_number, mini->out_fd);
	else
	{
		ft_putstr_fd(mini_tokens_i, mini->out_fd);
		g_ret_number = 0;
	}
}
