/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:29:06 by fmoreira          #+#    #+#             */
/*   Updated: 2023/01/01 22:30:00 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_in(t_minishell *mini, int c, char *aux)
{
	char	**file;

	if (mini->commands[c][0] == '<')
	{
		file = NULL;
		if (mini->commands[c][1] == '<')
			file = re_redir(mini, file, c);
		else
		{
			file = ft_split(&mini->commands[c][1], ' ');
			mini->input_fd = open(file[0], O_RDONLY, 0644);
			if (mini->input_fd == -1 && mini->error_name_file == NULL)
				mini->error_name_file = ft_strdup("");
		}
		aux = ft_strtrim(mini->line, " ");
		if (mini->split.qtt_comand == 1 || (aux[0] == '|'
				&& ft_strlen(aux) == 1))
		{
			free(mini->line);
			mini->line = new_comman(1, file, mini->input_fd);
		}
		free(aux);
		mini->redirect = 0;
		free_array(file);
	}
}

char	**re_redir(t_minishell *mini, char **file, int c)
{
	file = ft_split(&mini->commands[c][2], ' ');
	read_until(mini, file[0]);
	mini->input_fd = open(file[0], O_RDONLY | O_CREAT, 0644);
	if (mini->input_fd == -1 && mini->error_name_file == NULL)
	{
		mini->error_name_file = ft_strdup("");
		close(mini->input_fd);
		return (file);
	}			
	mini->name_file = ft_strdup(file[0]);
	mini->append++;
	return (file);
}

void	read_until(t_minishell *mini, char *file)
{
	char	*line;
	int		flags;
	int		fd;

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	line = ft_strdup("");
	fd = open(file, flags, 0644);
	if (fd == -1 && mini->error_name_file == NULL)
	{
		mini->error_name_file = NULL;
		close(fd);
		return ;
	}		
	while (ft_strncmp(line, file, ft_strlen(file))
		|| ft_strlen(line) != ft_strlen(file))
	{
		free(line);
		line = readline("> ");
		if (ft_strlen(line) != ft_strlen(file))
			ft_putendl_fd(line, fd);
	}
	close(fd);
	free(line);
}

char	*new_comman(int i, char **file, int fd)
{
	char	*aux;

	aux = ft_strdup("");
	if (file[0])
	{
		while (file[i] != NULL)
		{
			if (ft_strlen(aux) > 0)
				aux = ft_strjoin(aux, " ");
			aux = ft_strjoin(aux, file[i]);
		}
		return (aux);
	}
	else
	{
		close(fd);
		return (aux);
	}
}
