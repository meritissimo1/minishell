/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:04:40 by marcrodr          #+#    #+#             */
/*   Updated: 2022/09/12 19:45:33 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H 

# include "libft.h"
# include "felpo.h"

typedef struct s_node
{
	struct s_node	*next;
	char			*path;
}t_node;

typedef struct s_path
{
	t_node	*env;
}t_path;

int check_args(int argc);



#endif