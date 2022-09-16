/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   felpo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:52:40 by fmoreira          #+#    #+#             */
/*   Updated: 2022/09/16 02:27:11 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define	MINISHELL_H
#include <stdio.h>
#include "../libs/libft/libft.h"

typedef	struct	s_nenv
{
	char			*var;
	char			*content;
	struct s_nenv	*next;
}	t_nenv;

typedef struct	s_env
{
	unsigned long int	size;
	struct s_nenv	*top_node;
}	t_env;



void	ft_initialize_list(t_env *env_list);
t_nenv	*ft_node_format(t_nenv	*node);
void	ft_more_envp(t_env *env_list, char **env);

#endif