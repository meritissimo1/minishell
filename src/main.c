/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:03:35 by marcrodr          #+#    #+#             */
/*   Updated: 2022/12/16 18:26:44 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_input_line(char *prompt);

int g_ret_number;

int main(int argc, char **argv, char **env)
{
	t_minishell	mini;
	char		*command_line;

	(void)argv;
	check_args(argc); 	// error.c
	init(&mini, env); 		// init.c
	(void)argv;
	while(42)
	{
		mini.out_fd = STDOUT_FILENO;
		mini.input_fd = STDIN_FILENO;
		define_signals();	//	signal.c
		command_line = get_input_line(PROMPT);
		if (command_line == NULL)
			break ;
		if (strncmp(command_line, "", 1) != 0)
			add_history(command_line);
		if (!strncmp(command_line, "faze", 7))	//	remover depois
			exit(0);
		mini.rawline = command_line;
		split_cmd(&mini, command_line, 0);		//	parser_split.c
		if (mini.split.qtt_comand > 0 && mini.commands[0][0] != '|')
			exec_commands(&mini);//	exec_commands.c
		if (mini.commands[0] && mini.commands[0][0] == '|')
			printf(ERROR_PIPE);
		free_commands(mini.commands);//	token.c
	}
	return (0);
}
