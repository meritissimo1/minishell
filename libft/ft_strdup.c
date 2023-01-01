/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:11:31 by user42            #+#    #+#             */
/*   Updated: 2023/01/01 22:23:47 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*str;

	size = ft_strlen(s1) + 1;
	str = ((char *)malloc(sizeof(char) * size));
	if (!str)
		return (0);
	while (size--)
	{
		((unsigned char *)str)[size] = ((unsigned char *)s1)[size];
	}
	return (str);
}
