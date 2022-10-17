/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:06:09 by marcrodr          #+#    #+#             */
/*   Updated: 2022/10/17 12:07:14 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*init_tk()
{
	t_token	*tk;

	tk = (t_token *)malloc(sizeof(t_token));
	tk->end = NULL;
	tk->new = NULL;
	tk->exec = NULL;
	tk->print = NULL;
	tk->quote = '\0';
	tk->i = 0;
	tk->init = 0;
	tk->len = 1;
	tk->posic = 0;
	return (tk);	
}