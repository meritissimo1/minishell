/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_by_idx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:17:25 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/01 22:23:01 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_by_idx(char const *s, int idx)
{
	char	**split;
	int		i;

	split = malloc(sizeof(char *) * (2 + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (s[i] && i < idx)
		i++;
	split[0] = ft_substr(s, 0, i);
	split[1] = ft_substr(s, i + 1, ft_strlen(s) - i);
	split[2] = NULL;
	return (split);
}
