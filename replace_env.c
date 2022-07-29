// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   replace_env.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/07/27 17:23:43 by ibenmain          #+#    #+#             */
// /*   Updated: 2022/07/28 17:43:53 by ibenmain         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"

// int	check_cmp(int i, char *line, char *env)
// {
// 	int	j;

// 	j = -1;
// 	while (env[j++])
// 	{
// 		if (line[i++] == env[j])
// 			continue ;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

// char	*get_new_value(int i, char *line, t_env *env)
// {
// 	int		k;
// 	int		j;
// 	char	*str;

// 	k = -1;
// 	j = 0;
// 	str = (char *)malloc(sizeof(char *));
// 	while (env)
// 	{
// 		if (check_cmp(i, line, env->var))
// 		{
// 			while (env->val[++k])
// 				str[k] = env->val[k];
// 			// break ;
// 		}
// 		// else
// 		// 	str[k] = line[k];
// 		env = env->next;
// 	}
// 	return (str);
// }

// char	*check_var(char *line, t_env *env)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	str = (char *)malloc(sizeof(char *));
// 	while (line[i] != '\0')
// 	{
// 		if (line[i] == '$')
// 			str = get_new_value(i + 1, line, env);
// 		i++;
// 	}
// 	printf("---->>%s\n" ,str);
// 	return (str);
// }

// int	check_dollar_exist(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[++i])
// 	{
// 		if (str[i] == '$')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// t_tok	*replace_env(t_tok *lst, t_env *env)
// {
// 	int		i;
// 	t_tok	*tmp;
// 	t_env	*env;

// 	tmp = lst;
// 	while (tmp)
// 	{
// 		i = 0;
// 		if (tmp->value[i] == '$')
// 		{
// 			check_cmp(tmp->value);
// 		}
// 		else
// 			tmp = tmp->next;
// 	}
// 	return (lst);
// }
