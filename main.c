/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:42:32 by ibenmain          #+#    #+#             */
/*   Updated: 2022/07/24 11:45:58 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_env	*data;

	(void)argc;
	(void)argv;
	data = malloc(sizeof(t_env));
	if (!data)
		return (0);
	desplay_shell(env);
	return (0);
}
