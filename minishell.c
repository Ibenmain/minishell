/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:25:10 by ibenmain          #+#    #+#             */
/*   Updated: 2022/07/25 21:55:34 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	desplay_shell(char **data)
{
	t_env	*env;
	char	*str;

	env = malloc(sizeof(t_env));
	if (!env)
		return ;
	init_sig();
	env = init_env(data);
	while (1)
	{
		str = readline("\033[0;33m\e[1mMinishell ✗\e[0m\033[0m ");
		if (!str)
			return ;
		add_history(str);
		check_line(str);
		free(str);
	}
}
