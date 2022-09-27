/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char_validated.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:37:22 by marcrodr          #+#    #+#             */
/*   Updated: 2022/09/27 11:38:43 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quote_apostrofhe(char c)
{
	if (c == '\"' || c == '\'')
		return (1);
	return (0);
}

int	is_operator(char c)
{
	if (c == '>' || c == '<' ||
		c == '&' || c == '|' )
		return (1);
	return (0);
}
