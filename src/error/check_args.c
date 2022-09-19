/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:56:42 by marcrodr          #+#    #+#             */
/*   Updated: 2022/09/19 14:49:45 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_args(int argc)
{
	if (argc > 1)
	{
		printf("Error, minishell more than one param\n");
		exit(0);
	}
	return (0);
}
