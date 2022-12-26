/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:42:59 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/27 00:55:54 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_echo_list	ft_init_echo(t_minishell *mini, char *rawline)
{
	t_echo_list	echo_list;
	//int			count;
	
	//count = 0;
	ft_init_echo_list(&echo_list);
	echo_list.top_node = ft_echo_node_format(echo_list.top_node);
	echo_list.top_node->token = ft_more_echo_token(mini, rawline);
	
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
	i = 5;
	j = 0;
	while (raw_aux[i])
	{
		if (raw_aux[i] == (D_QUOTE || QUOTE))
		{
			raw_aux++;
			while (raw_aux[i] == D_QUOTE)
			{
				pre_node[j++] = raw_aux[i++];
				if (!raw_aux[i])
				{
					printf("\" not found\n");
					break ;
				}
				else if (raw_aux[i] == D_QUOTE)
				{
					raw_aux++;
					pre_node[++j] = NULL; //possivelmente por no echo_node
					break;
				}
				else if (raw_aux[i] == "$")
				{
					raw_aux++;
					while (!ft_isalnum(raw_aux[i]))
					{
						env_find = raw_aux[i];
						i++;
					}
					env_find[i] = NULL;
					env_find = ft_env_content(mini->envp, env_find);
					if	(env_find != 1)
						i += ft_strlen(env_find);
					ft_strjoin(pre_node, env_find);
				}
				// check if d_quote is close
			}
		}
	}
	printf("%s\n", pre_node);
	
}
