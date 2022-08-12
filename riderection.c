/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   riderection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:39:15 by ibenmain          #+#    #+#             */
/*   Updated: 2022/08/12 21:10:20 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_great(char *str, int i, t_tok **head)
{
	int	j;

	j = 0;
	if (str[i] == '>' && str[i + 1] == '>')
	{
		j = i;
		while (str[i] && str[i] == '>')
			i++;
		ft_add_back(head, creat_token(j, (i - j), str, OUT_RED));
		return (i);
	}
	ft_add_back(head, creat_token(i, 1, str, OUT_RED));
	return (i + 1);
}

int	ft_get_less(char *str, int i, t_tok **head)
{
	int	j;

	j = 0;
	if (str[i] == '<' && str[i + 1] == '<')
	{
		j = i;
		while (str[i] && str[i] == '<')
			i++;
		ft_add_back(head, creat_token(j, (i - j), str, IN_RED));
		return (i);
	}
	ft_add_back(head, creat_token(i, 1, str, IN_RED));
	return (i + 1);
}

int	ft_get_pipe(char *str, int i, t_tok **head)
{
	if (str[i] == '|')
		ft_add_back(head, creat_token(i, 1, str, PIPE));
	return (i + 1);
}

int	ft_get_double(char *str, int i, t_tok **head)
{
	int	j;

	if (str[i] == '"' && str[i + 1] == '"')
		ft_add_back(head, creat_token(i, 2, str, D_QOUT));
	else
	{
		j = i;
		i = i + 1;
		while (str[i] && str[i] != '"')
			i++;
		ft_add_back(head, creat_token(j, (i - j) + 1, str, D_QOUT));
		return (i + 1);
	}
	return (i + 2);
}

int	ft_get_single(char *str, int i, t_tok **head)
{
	int	j;

	if (str[i] == '\'' && str[i + 1] == '\'')
		ft_add_back(head, creat_token(i, 2, str, S_QOUT));
	else
	{
		j = i;
		i = i + 1;
		while (str[i] && str[i] != '\'')
			i++;
		ft_add_back(head, creat_token(j, (i - j) + 1, str, S_QOUT));
		return (i + 1);
	}
	return (i + 2);
}
