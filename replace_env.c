/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:23:43 by ibenmain          #+#    #+#             */
/*   Updated: 2022/08/11 01:44:06 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(char *str1, int i, char *str2)
{
	int	j;

	j = 0;
	while ((str1[i] && str1[i] != '$') || str2[j])
	{
		if (str1[i] != str2[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	j;

	j = 0;
	while (str1[j] || str2[j])
	{
		if (str1[j] != str2[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_get_value_of_env(char *line, int i, t_env *env)
{
	char	*str;
	int		j;

	j = 0;
	(void)line;
	(void)i;
	str = (char *)malloc(sizeof(char *));
	if (!str)
		return (NULL);
	while (env->val[j])
	{
		str[j] = env->val[j];
		j++;
	}
	return (str);
}

char	*check_cmp(char *line, int i, t_env *env)
{
	int		k;
	char	*str;

	str = malloc(sizeof(char *));
	if (!str)
		return (NULL);
	str = "";
	while (env)
	{
		k = i;
		if (!ft_strncmp(line, k + 1, env->var))
		{
			str = ft_get_value_of_env(line, k + 1, env);
			return (str);
		}
		else
			env = env->next;
	}
	return (str);
}

char	*ft_get_copy(char *str, char *line, int i)
{
	int	j;

	j = 0;
	while (str[j])
	{
		line[i] = str[j];
		i++;
		j++;
	}
	return (line);
}

char	*ft_check_qout(char *str)
{
	int		i;
	int		qout;
	char	*s;

	i = 0;
	qout = -1;
	s = malloc(sizeof(char *));
	if (!s)
		return (NULL);
	if (str[0] == '"' || str[0] == '\'')
	{
		qout = 1;
		i++;
		while (str[i] == '"')
			i++;
		while (str[i] && str[i] != '"' && str[i] != '\'')
		{
			if (str[i + 1] == '"')
				qout = 0;
			i++;
		}
		if (qout == 1)
			return (ft_substr(str, 1, i));
		else if (qout == 0)
			return (ft_substr(str, 1, i - 1));
	}
	else
	{
		while (str[i] && str[i] != '"' && str[i] != '\'')
		{
			if (str[i + 1] == '"')
				qout = 0;
			i++;
		}
		if (qout == 0)
			return (ft_substr(str, 0, i));
	}
	return (str);
}

t_tok	*replace_env(t_tok *lst, t_env *env)
{
	int		i;
	t_tok	*tmp;
	char	*str;

	tmp = lst;
	str = malloc(sizeof(char *));
	if (!str)
		return (NULL);
	while (tmp)
	{
		i = 0;
		tmp->value = ft_check_qout(tmp->value);
		while (tmp->value[i])
		{
			if (tmp->value[i] == '$')
			{
				str = check_cmp(tmp->value, i, env);
				if (!ft_strcmp(str, ""))
					tmp->value = "";
				else
					tmp->value = ft_get_copy(str, tmp->value, i);
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (lst);
}
