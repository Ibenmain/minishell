/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:48:38 by ibenmain          #+#    #+#             */
/*   Updated: 2022/07/25 17:03:53 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_index(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '<' || line[i] == '>')
	{
		while (line[i] == '<' || line[i] == '>')
			i++;
	}
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			i++;
			while (line[i]
				&& line[i] != '\'' && line[i] != '"')
				i++;
		}
		else if (line[i] == '<' || line[i] == '>')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_check_rid(char *line)
{
	int		i;
	int		idx;
	char	*str;

	i = 0;
	while (line[i])
	{
		idx = get_index(line);
		str = ft_substr(line, 0, idx);
		line = &line[idx];
		free(str);
		i = 0;
	}
}
