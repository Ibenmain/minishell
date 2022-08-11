/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:57:33 by ibenmain          #+#    #+#             */
/*   Updated: 2022/08/10 20:03:52 by ibenmain         ###   ########.fr       */
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

// t_tok	*ft_creat_token(char *str)
// {
// 	t_tok	*lst;

// 	lst = malloc(sizeof(t_tok));
// 	if (!lst)
// 		return (NULL);
// 	lst->value = ft_substr(str, 0, ft_strlen(str) + 1);
// 	lst->next = NULL;
// 	return (lst);
// }

// t_tok	*get_rid(char *str)
// {
// 	t_tok	*lst;

// 	lst = NULL;
// 	if (*str == '>')
// 		ft_add_back(&lst, ft_creat_token(">"));
// 	else if (*str == '<')
// 		ft_add_back(&lst, ft_creat_token("<"));
// 	else if (*str == '|')
// 		ft_add_back(&lst, ft_creat_token("|"));
// 	else if (*str == '>' && *(str + 1) == '>')
// 		ft_add_back(&lst, ft_creat_token(">>"));
// 	return (lst);
// }

/*------------------------------------------------------------------*/

t_tok	*creat_token(int start, int len, char *str, int typ)
{
	t_tok	*lst;

	lst = (t_tok *)malloc(sizeof(t_tok));
	if (!lst)
		return (NULL);
	lst->value = ft_substr(str, start, len);
	lst->type = typ;
	lst->next = NULL;
	return (lst);
}

int	ft_get_great(char *str, int i, t_tok **head)
{
	int	j;

	j = 0;
	if (str[i] == '>' && str[i + 1] == '>')
	{
		j = i;
		while (str[i] && str[i] == '>')
			i++;
		ft_add_back(head, creat_token(j, (i - j), str, OUT_RED));
		return (i);
	}
	ft_add_back(head, creat_token(i, 1, str, OUT_RED));
	return (i + 1);
}

int	ft_get_less(char *str, int i, t_tok **head)
{
	int	j;

	j = 0;
	if (str[i] == '<' && str[i + 1] == '<')
	{
		j = i;
		while (str[i] && str[i] == '<')
			i++;
		ft_add_back(head, creat_token(j, (i - j), str, IN_RED));
		return (i);
	}
	ft_add_back(head, creat_token(i, 1, str, IN_RED));
	return (i + 1);
}

int	ft_get_word(char *str, int i, t_tok **head)
{
	int	j;

	j = i;
	while (str[i] && str[i] != '>'
		&& str[i] != '<' && str[i] != '|' && str[i] != ' ')
		i++;
	ft_add_back(head, creat_token(j, (i - j), str, WORD));
	return (i);
}

int	ft_get_pipe(char *str, int i, t_tok **head)
{
	if (str[i] == '|')
		ft_add_back(head, creat_token(i, 1, str, PIPE));
	return (i + 1);
}

int	ft_get_double(char *str, int i, t_tok **head)
{
	int	j;

	if (str[i] == '"' && str[i + 1] == '"')
		ft_add_back(head, creat_token(i, 2, str, D_QOUT));
	else
	{
		j = i;
		i = i + 1;
		while (str[i] && str[i] != '"')
			i++;
		ft_add_back(head, creat_token(j, (i - j) + 1, str, D_QOUT));
		return (i + 1);
	}
	return (i + 2);
}

int	ft_get_single(char *str, int i, t_tok **head)
{
	int	j;

	if (str[i] == '\'' && str[i + 1] == '\'')
		ft_add_back(head, creat_token(i, 2, str, S_QOUT));
	else
	{
		j = i;
		i = i + 1;
		while (str[i] && str[i] != '\'')
			i++;
		ft_add_back(head, creat_token(j, (i - j) + 1, str, S_QOUT));
		return (i + 1);
	}
	return (i + 2);
}

int	check_space(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

t_tok	*ft_tokens(char *str)
{
	int				i;
	int				j;
	t_tok			*head;

	i = 0;
	j = 0;
	head = NULL;
	while (str[i])
	{
		i = check_space(str, i);
		if (str[i] == '>')
			i = ft_get_great(str, i, &head);
		else if (str[i] == '<')
			i = ft_get_less(str, i, &head);
		else if (str[i] == '|')
			i = ft_get_pipe(str, i, &head);
		else if (str[i] == '"')
			i = ft_get_double(str, i, &head);
		else if (str[i] == '\'')
			i = ft_get_single(str, i, &head);
		else
			i = ft_get_word(str, i, &head);
	}
	return (head);
}
