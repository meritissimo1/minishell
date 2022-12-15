/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:20:16 by marcrodr          #+#    #+#             */
/*   Updated: 2022/12/15 16:26:37 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(t_minishell *mini)
{
	mini->redirect = 0;
	g_ret_number = 0;
	mini->tokens = (char **) NULL;
	mini->envp = ft_initialize_env(env);
	mini->home = ft_strdup(find_env(mini, "HOME"));
	init_path(mini);
}
