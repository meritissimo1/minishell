	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:38:25 by marcrodr          #+#    #+#             */
/*   Updated: 2022/10/14 17:20:03 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*skip_space(char *str)
{
	char	*aux;

	aux = ft_strtrim(str, " ");
	str = aux;
	return (str);
}

void	ft_print_ppc(char  **splited, int fd, int aux)
{
	int		i;
	char	ok;
	i = 0;
	ok = 0;
	while (splited[i++])
	{
		if (aux == 1 && ok++ < 1)
			i++;
		ft_putstr_fd(splited[i], fd);
		if (splited[i + 1] == NULL)
			i++;
		write(fd, " ", 1);
	}
	if (aux == 0)
		write(fd, "\n", 1);
}

void	init_split(t_minishell *mini)
{
	mini->split.qtt_comand = 0;
	mini->split.ini = 0;
	mini->split.len = 0;
	mini->split.qtt_pipe = 0;
	mini->split.quote = 0;
	mini->redirect = 0;
}

void	finish_tokenizer(t_minishell *mini, t_token *tk)
{
	tk->new = ft_substr(mini->line, tk->init, tk->len);
	tk->end = ft_strjoin(tk->end, tk->new);
	tk->posic = tokenizer_find_char(tk->end, ' ');
	mini->token.print = ft_strtrim(&(tk->end)[tk->posic], " ");
	mini->token.exec = ft_substr(tk->end, tk->i + 1, tk->posic);
	check_flags(mini, mini->token.print, 0, 0);
	mini->tokens = ft_split(tk->end, ' ');
	free_tk(tk);
	free(mini->line);
}

void	free_tk(t_token *tk)
{
	if (tk->end != NULL)
	{
		free(tk->end);
		tk->end = NULL;
	}
	if (tk->new != NULL)
	{
		free(tk->new);
		tk->new = NULL;
	}
	if (tk->exec != NULL)
	{
		free(tk->exec);
		tk->exec = NULL;
	}
	if (tk->print != NULL)
	{
		free(tk->print);
		tk->print = NULL;
	}
	free(tk);
}