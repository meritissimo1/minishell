/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:07:02 by fmoreira          #+#    #+#             */
/*   Updated: 2022/10/03 20:30:14 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *cmd_line)
{
	char	**splited;

	splited = ft_split(cmd_line, 32);
	ft_print_ppc(splited, 0);  // printa o comando ***precisa ser reavalidade de sua utilidade***
	if (ft_strcmp(splited[2], "-n"))
		ft_print_ppc(splited + 2, 0);
	else
		ft_print_ppc(splited, 1);
}
