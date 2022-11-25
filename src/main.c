/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:03:35 by marcrodr          #+#    #+#             */
/*   Updated: 2022/11/23 12:54:22 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_input_line(char *prompt);

int main(int argc, char **argv, char **env)
{
	t_minishell	mini;
	char		*command_line;

	check_args(argc);
	mini.envp = initialize_env(env);
	//ft_env(&envp);//	teste do builtin "env"
	//ft_echo("echo -n aopa meu brasil");
	//ft_pwd(&envp);//	teste do builtin "pwd"
	(void)argv;
	while(42) 
	{
		define_signals();
		command_line = get_input_line(PROMPT);
		if (command_line == NULL)
			break ; 
		if (strncmp(command_line, "", 1) != 0)
			add_history(command_line);
		if (!strncmp(command_line, "faze", 7)) // remover depois
			exit(0);
		split_cmd(&mini, command_line, 0);
		if (mini.split.qtt_comand > 0 && mini.commands[0][0] != '|')
			exec_commands(&mini);
	}
	return (0);
}

char	*get_input_line(char *prompt)
{
	char	*input;
	input = readline(prompt);
	if (input == NULL)
		return (NULL);
	else
		return(input);
}
