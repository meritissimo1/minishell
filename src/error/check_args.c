/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:56:42 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/01 22:27:40 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_args(int argc)
{
	if (argc > 1)
	{
		printf("Error, minishell more than one param\n");
		exit(0);
	}
	return (0);
}
