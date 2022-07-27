/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:20:02 by ibenmain          #+#    #+#             */
/*   Updated: 2022/07/27 19:55:17 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_line(char *line, t_env *env)
{
	t_tok	*lst;

	lst = (t_tok *)malloc(sizeof(t_tok));
	if (!lst)
		return ;
	lst = tokens(line);
	lst = replace_env(lst, env);
	while (lst)
	{
		printf("%s\n", lst->value);
		lst = lst->next;
	}
}
