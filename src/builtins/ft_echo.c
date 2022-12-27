/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:07:02 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/27 02:30:09 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
char	**ft_token_rawline(char **tokens, char *rawline);


void	ft_echo(t_minishell *mini)
{
	printf("aqui foi 00\n");
	ft_init_echo(mini, mini->rawline);
	
}
