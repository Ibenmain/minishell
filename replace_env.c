/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:23:43 by ibenmain          #+#    #+#             */
/*   Updated: 2022/08/08 05:20:44 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *str1, int i, char *str2)
{
	int	j;

	j = 0;
	while (str1[i] || str2[j])
	{
		if (str1[i] != str2[j])
			return (1);
		i++;
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

// char	*ft_get_value(char *line, int i)
// {
// 	char	*str;
// 	int		j;

// 	j = 0;
// 	str = (char *)malloc(sizeof(char *));
// 	if (!str)
// 		return (NULL);
// 	while (line[j] && i != j)
// 	{
// 		str[j] = line[j];
// 		j++;
// 	}
// 	return (str);
// }

char	*check_cmp(char *line, int i, t_env *env)
{
	int		k;
	char	*str;

	str = malloc(sizeof(char *));
	if (!str)
		return (NULL);
	while (env)
	{
		k = i;
		if (!ft_strcmp(line, k + 1, env->var))
		{
			str = ft_get_value_of_env(line, k + 1, env);
		}
		// else
		// {
		// 	str = ft_get_value(line, k);
		// }
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
		while (tmp->value[i])
		{
			if (tmp->value[i] == '$')
			{
				str = check_cmp(tmp->value, i, env);
				tmp->value = ft_get_copy(str, tmp->value, i);
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (lst);
}
