/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:42:59 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/27 03:27:22 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_echo_list	ft_init_echo(t_minishell *mini, char *rawline)
{
	t_echo_list	echo_list;
	//int			count;
	
	//count = 0;
	ft_init_echo_list(&echo_list);
	printf("aqui foi 01\n");
	echo_list.top_node = ft_echo_node_format(echo_list.top_node);
	printf("aqui foi 02\n");
	echo_list.top_node->token = ft_more_echo_token(mini, rawline);
	printf("aqui foi 03\n");
	return (echo_list);
}

void	ft_init_echo_list(t_echo_list *echo_list)
{
	echo_list->size = 0;
	echo_list->top_node = NULL;
}

t_echo_node	*ft_echo_node_format(t_echo_node *node)
{
	node = (t_echo_node *)malloc(sizeof(t_echo_node));
	node->next = NULL;
	if (!node)
		exit(0);
	return (node);
}

char	*ft_more_echo_token(t_minishell *mini, char *rawline)
{
	int	i;
	int j;
	char	*raw_aux;
	char	*pre_node;
	char	*env_find;

	raw_aux = rawline;
	pre_node = (char *)ft_calloc(sizeof(ft_strlen(rawline)), 1);
	i = 5;
	j = 0;
	while (raw_aux[i])
	{
		printf("aqui foi 03.1 %d\n", i);
		if (raw_aux[i] == D_QUOTE || raw_aux[i] == QUOTE)
		{
			raw_aux++;
			while (raw_aux[i + 1] != D_QUOTE || raw_aux[i])
			{
				pre_node[j++] = raw_aux[i];
				printf("%c", raw_aux[i]);
				if (raw_aux[i] == '$')
				{
					raw_aux++;
					j = 0;
					while (!ft_isalnum(raw_aux[i]))
					{
						env_find[j++] = raw_aux[i];
						i++;
					}
					env_find[i] = 0;
					env_find = ft_env_content(&mini->envp, env_find);
					if	(env_find != (char *)1)
						i += ft_strlen(env_find);
					pre_node = ft_strjoin(pre_node, env_find);
					printf("aqui foi 03.5\n");
				}
				else if (!raw_aux[i])
				{
					printf("\" not found\n");
					break ;
				}
				i++;	// check if d_quote is close
			}
			i++;
		}
		raw_aux++;
		pre_node[++j] = 0;
		i++;
	}
	pre_node[i] = 0;
	printf("pre_node %s\n", pre_node);
	return (pre_node);
}
