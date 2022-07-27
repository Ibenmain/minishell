/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:23:43 by ibenmain          #+#    #+#             */
/*   Updated: 2022/07/27 19:55:50 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_new_value(int i, char *line, t_env *env)
{
	int		k;
	char	*str;

	k = -1;
	str = (char *)malloc(sizeof(char *));
	while (env)
	{
		if (line[i] == env->var[0])
		{
			while (env->val[++k] != '\0')
					str[k] = env->val[k];
			break;
		}
		env = env->next;
	}
	return (str);
}

char	*check_var(char *line, t_env *env)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char *));
	while (line[i] != '\0')
	{
		if (line[i] == '$')
			str = get_new_value(i + 1, line, env);
		i++;
	}
	return (str);
}

t_tok   *replace_env(t_tok *lst, t_env *env)
{
	int	i;
	t_tok	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{

		if (tmp->value[0] == '$')
		{
			tmp->value = check_var(tmp->value, env);
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	return (lst);
}
