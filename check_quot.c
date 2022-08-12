/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:18:13 by ibenmain          #+#    #+#             */
/*   Updated: 2022/08/12 01:24:14 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_check_scend_quot(char *str, int i, int quot)
{
	i++;
	if (str[i] == '"')
		return ("");
	while (str[i] && str[i] != '"' && str[i] != '\'')
	{
		if (str[i + 1] == '"')
			quot = 0;
		i++;
	}
	if (quot == 0)
		return (ft_substr(str, 1, i - 1));
	return ("Syntaxe Error\n");
}

char	*ft_check_scend_quot2(char *str, int i, int quot)
{
	while (str[i] && str[i] != '"' && str[i] != '\'')
	{
		if (str[i + 1] == '"')
			return ("");
		i++;
	}
	if (quot == 0)
		return ("Syntaxe Error\n");
	return (str);
}

char	*ft_check_qout(char *str)
{
	int		i;
	int		quot;
	char	*s;

	i = 0;
	quot = -1;
	s = malloc(sizeof(char *));
	if (!s)
		return (NULL);
	if (str[i] == '"' || str[i] == '\'')
	{
		quot = 1;
		s = ft_check_scend_quot(str, i, quot);
		return (s);
	}
	else
	{
		s = ft_check_scend_quot2(str, i, quot);
		return (s);
	}
	return (str);
}
