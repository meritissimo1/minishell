/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:34:30 by marcrodr          #+#    #+#             */
/*   Updated: 2022/12/31 22:21:26 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_builtin(t_minishell *mini, char *cmd)
{
	if ((!ft_strncmp("echo", cmd, 4) && ft_strlen(cmd) == 4)
		|| (!ft_strncmp("pwd", cmd, 3) && ft_strlen(cmd) == 3)
		|| (!ft_strncmp("env", cmd, 3) && ft_strlen(cmd) == 3)
		|| (!ft_strncmp("exit", cmd, 4) && ft_strlen(cmd) == 4)
		|| (!ft_strncmp("cd", cmd, 2) && ft_strlen(cmd) == 2)
		|| (!ft_strncmp("export", cmd, 6) && ft_strlen(cmd) == 6)
		|| (!ft_strncmp("unset", cmd, 5) && ft_strlen(cmd) == 5))
		mini->is_builtin = true;
	else
		mini->is_builtin = false;
}
