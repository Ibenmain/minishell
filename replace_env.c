/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:23:43 by ibenmain          #+#    #+#             */
/*   Updated: 2022/08/11 16:18:56 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
