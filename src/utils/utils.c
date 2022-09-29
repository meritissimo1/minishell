/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:38:25 by marcrodr          #+#    #+#             */
/*   Updated: 2022/09/29 11:40:06 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_skip_space(char *str)
{
	char	*ret;

	while (ft_isspace(*str))
		str++;
	ret = str;
	return (ret);
}