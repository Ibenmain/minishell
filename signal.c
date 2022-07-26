/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:35:03 by ibenmain          #+#    #+#             */
/*   Updated: 2022/07/25 21:53:54 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line(" ", 0);
		rl_redisplay();
	}
}

void	init_sig(void)
{
	if (signal(SIGINT, sigint_handler))
		return ;
	if (signal(SIGQUIT, SIG_IGN))
		return ;
}
