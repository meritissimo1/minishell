/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:15:23 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/01 22:23:25 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_idx(const char *str, int c)
{
	char	*ptr;
	int		i;
	int		len_s;

	len_s = 0;
	while (str[len_s])
		len_s++;
	ptr = (char *)str;
	i = 0;
	while (i < len_s + 1)
	{
		if (ptr[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
