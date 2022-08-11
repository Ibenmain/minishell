/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:57:33 by ibenmain          #+#    #+#             */
/*   Updated: 2022/08/11 15:40:35 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
