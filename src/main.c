/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:03:35 by marcrodr          #+#    #+#             */
/*   Updated: 2022/12/30 16:17:00 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_input_line(char *prompt);

int g_ret_number;

int main(int argc, char **argv, char **env)
{
	t_minishell	mini;

	(void)argv;
	check_args(argc); 	// error.c
	init(&mini, env); 		// init.c
	(void)argv;
	while(42)
	{
		mini.out_fd = STDOUT_FILENO;
		mini.input_fd = STDIN_FILENO;
		define_signals();	//	signal.c
		mini.rawline = get_input_line(PROMPT);		
		if (mini.rawline == NULL)
			break ;
		if (strncmp(mini.rawline, "", 1) != 0)
			add_history(mini.rawline);
		split_cmd(&mini, mini.rawline, 0);		//	parser_split.c
		if (mini.split.qtt_comand > 0 && mini.commands[0][0] != '|')
			exec_commands(&mini);//	exec_commands.c
		if (mini.commands[0] && mini.commands[0][0] == '|')
			printf(ERROR_PIPE);
		free_commands(mini.commands);//	token.c
		free(mini.rawline);
	}
	return (0);
}
