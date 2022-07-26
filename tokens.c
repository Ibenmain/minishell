/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:57:33 by ibenmain          #+#    #+#             */
/*   Updated: 2022/07/26 01:19:56 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_back(t_tok **alst, t_tok *new)
{
	t_tok	*ptr;

	if (alst)
	{
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
}

t_tok	*ft_creat_token(char *str)
{
	t_tok	*lst;

	lst = malloc(sizeof(t_tok));
	if (!lst)
		return (NULL);
	lst->value = ft_substr(str, 0, ft_strlen(str) + 1);
	return (lst);
}

t_tok	*get_rid(char str)
{
	t_tok	*head;

	head = NULL;
	if (str == '>')
		ft_add_back(&head, ft_creat_token(">"));
	else if (str == '<')
		ft_add_back(&head, ft_creat_token("<"));
	else if (str == '|')
		ft_add_back(&head, ft_creat_token("|"));
	else if (str == '$')
		ft_add_back(&head, ft_creat_token("$"));
	return (head);
}

/*------------------------------------------------------------------*/

t_tok	*get_str(char *str)
{
	t_tok	*head;

	head = NULL;
	ft_add_back(&head, ft_creat_token(str));
	return (head);
}

t_tok	*tokens(char *str)
{
	int		i;
	t_tok	*head;
	int		index;

	i = 0;
	index = 0;
	head = malloc(sizeof(t_tok));
	if (!head)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '>' || str[i] == '<' || str[i] == '|' || str[i] == '$')
		{
			if (index == 0)
			{
				head = get_rid(str[i]);
				index++;
			}
			else
				ft_add_back(&head, get_rid(str[i]));
		}
		i++;
	}
	return (head);
}
