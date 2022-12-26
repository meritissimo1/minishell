/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:42:59 by fmoreira          #+#    #+#             */
/*   Updated: 2022/12/26 19:08:37 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_echo_list	ft_init_echo(char *rawline)
{
	t_echo_list	echo_list;
	int			count;
	
	count = 0;
	ft_init_echo_list(&echo_list);
	echo_list.top_node = ft_echo_node_format(echo_list.top_node);
	
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

void	ft_more_echo_token(t_echo_list *echo_list, char *rawline)
{
	int	i;
	int j;
	char	*raw_aux;
	char	*pre_node;
	
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
				// check if d_quote is close
			}
		}
	}
	
}
