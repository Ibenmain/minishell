/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:25:10 by ibenmain          #+#    #+#             */
/*   Updated: 2022/06/30 17:54:51 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_index_key(char *data)
{
	int	i;

	i = -1;
	while (data[++i])
	{
		if (data[i] == '=')
			break ;
	}
	return (i);
}

char	*ft_key(char *data)
{
	int		len;
	char	*str;

	len = 0;
	len = ft_index_key(data);
	str = ft_substr(data, 0, len);
	return (str);
}

char	*ft_val(char *data)
{
	int		len;
	char	*str;

	len = ft_index_key(data);
	str = ft_substr(data, len + 1 ,ft_strlen(data) - len);
	return (str);
}

t_env	*ft_creat_node(char *data)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->var = ft_key(data);
	env->val = ft_val(data);
	env->next = NULL;
	return (env);

}

void	init_env(t_env	*head, char **env)
{
	int		i;

	i = -1;
	head = malloc(sizeof(t_env));
	if (!head)
		return ;
	while (env[++i])
		ft_lstadd_back(&head, ft_creat_node(env[i]));
	while (head->next)
	{
		printf("%s=%s",head->val, head->val);
	}
	
}

void	desplay_shell(t_env **env, char **data)
{
	
	init_env(*env, data);
}
