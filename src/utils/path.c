/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:17:43 by marcrodr          #+#    #+#             */
/*   Updated: 2022/11/30 18:23:59 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	init_path(t_minishell *mini)
{
	char	*path_aux;
	int		i;

	path_aux = ft_strdup(find_env(mini, "PATH"));
	if (!path_aux)
		return (0);
	mini->path = ft_split(path_aux, ':');
	i = 0;
	while (mini->path && mini->path[i])
	{
		mini->path[i] = ft_strjoin(mini->path[i], "/");
		i++;
	}
	free(path_aux);
	return (1);
}