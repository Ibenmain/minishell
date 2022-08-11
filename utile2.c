/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:12:43 by ibenmain          #+#    #+#             */
/*   Updated: 2022/08/11 15:16:43 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_back(t_tok **alst, t_tok *new)
{
	t_tok	*ptr;

	if (*alst == NULL)
	{
		*alst = new;
		new = NULL;
	}
	else
	{
		ptr = *alst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

int	check_space(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}
