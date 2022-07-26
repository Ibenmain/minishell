/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:20:02 by ibenmain          #+#    #+#             */
/*   Updated: 2022/07/26 17:14:23 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_line(char *line)
{
	t_tok	*lst;

	lst = (t_tok *)malloc(sizeof(t_tok));
	if (!lst)
		return ;
	lst = tokens(line);
	while (lst)
	{
		printf("%s\n", lst->value);
		lst = lst->next;
	}
}
