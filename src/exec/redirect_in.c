#include "minishell.h"

void	redirect_in(t_minishell *mini, int c, char *aux)
{
	char	**file;

	(void)aux;
	if (mini->commands[c][0] == '<')
	{
		file = NULL;
		if (mini->commands[c][1] == '<')
		{
			file = re_redir(mini, file, c);
		}
	}
	
}

char	**re_redir(t_minishell *mini, char **file, int c)
{
	(void)c;
	file = ft_split(&mini->commands[c][2], ' ');
	read_until(file[0]);
	return (file);
}

void	read_until(char *file)
{
	char	*line;
	int		flags;
	int		fd;

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	line = ft_strdup("");
	fd = open(file, flags, 0777);
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
