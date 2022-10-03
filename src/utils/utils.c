/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:38:25 by marcrodr          #+#    #+#             */
/*   Updated: 2022/10/03 20:28:45 by fmoreira         ###   ########.fr       */
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

void	ft_print_ppc(char  **splited, int aux)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		printf("%s", splited[i++]);
		if (aux == 0)
			printf(" ");
		if (aux == 1 && ft_strcmp(splited[i], "\n"))
			break;
	}
	if (aux == 0)
		printf("\n");
}