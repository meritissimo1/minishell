/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 02:01:31 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/31 22:37:03 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_pwd(t_minishell *mini)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, 2000);
	ft_putstr_fd(buf, mini->out_fd);
	write(mini->out_fd, "\n", 1);
	if (buf == NULL)
		g_ret_number = 1;
	else
		g_ret_number = 0;
	return (buf);
	free(buf);
}
