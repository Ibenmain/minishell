/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aaaaaaaa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:57:33 by ibenmain          #+#    #+#             */
/*   Updated: 2022/07/30 15:46:26 by ibenmain         ###   ########.fr       */
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

t_tok	*ft_creat_token(char *str)
{
	t_tok	*lst;

	lst = malloc(sizeof(t_tok));
	if (!lst)
		return (NULL);
	lst->value = ft_substr(str, 0, ft_strlen(str) + 1);
	lst->next = NULL;
	return (lst);
}

t_tok	*get_rid(char *str)
{
	t_tok	*lst;

	lst = NULL;
	if (*str == '>')
		ft_add_back(&lst, ft_creat_token(">"));
	else if (*str == '<')
		ft_add_back(&lst, ft_creat_token("<"));
	else if (*str == '|')
		ft_add_back(&lst, ft_creat_token("|"));
	else if (*str == '>' && *(str + 1) == '>')
		ft_add_back(&lst, ft_creat_token(">>"));
	return (lst);
}

/*------------------------------------------------------------------*/

void	print_error(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

t_tok	*creat_token(int i, int j, char *str)
{
	t_tok	*lst;

	lst = (t_tok *)malloc(sizeof(t_tok));
	if (!lst)
		return (NULL);
	lst->value = ft_substr(str, j, i - j);
	lst->next = NULL;
	return (lst);
}

t_tok	*tokens(char *str)
{
	int				i;
	int				j;
	t_tok			*head;

	i = 0;
	j = 0;
	head = NULL;
	while (str[i])
	{
		if (str[i] == '>' || str[i] == '<' || str[i] == '|'
			|| str[i] == ' ' || str[i] == '"' || str[i] == '\'')
		{
			if ((str[i] == '>' && str[i + 1] == '>')
				|| (str[i] == '<' && str[i + 1] == '<'))
			{
				j = i;
				while ((str[i] && str[i] == '>') || str[i] == '<')
					i++;
				ft_add_back(&head, creat_token(i--, j, str));
			}
			else if (str[i] == '"' || str[i] == '\'')
			{
				j = i;
				if (str[i++] == '"')
				{
					while (str[i] != '"')
						i++;
					ft_add_back(&head, creat_token(i + 1, j, str));
				}
				else
				{
					while (str[i] != '\'')
						i++;
					ft_add_back(&head, creat_token(i + 1, j, str));
				}
			}
			else
				ft_add_back(&head, get_rid(&str[i]));
			i++;
		}
		else
		{
			while (str[i] == ' ')
				i++;
			j = i;
			while (str[i] && str[i] != '>'
				&& str[i] != '<' && str[i] != '|' && str[i] != ' ')
				i++;
			ft_add_back(&head, creat_token(i, j, str));
		}
	}
	return (head);
}
