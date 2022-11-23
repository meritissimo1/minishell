/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:39:03 by marcrodr          #+#    #+#             */
/*   Updated: 2022/11/22 17:23:51 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void handler(int signal)
{
	char c;
	c = signal + '0';
	write(1, &c, 1);	// escrevendo o signal	
	g_ret_number = 130;
	ft_putstr_fd("\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	exec_handler(int signal)
{
	char c;
	c = signal + '0';
	write(1, &c, 1);
	ft_putstr_fd("\n exec", 1);
	waitpid(-1, NULL, WUNTRACED);
	g_ret_number = 130;
}

void	define_exec_signals(void)
{
	signal(SIGINT, exec_handler);
}

void	define_signals(void)
{
	signal(SIGINT, handler);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
