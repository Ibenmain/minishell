/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:12:43 by ibenmain          #+#    #+#             */
/*   Updated: 2022/08/12 21:07:35 by ibenmain         ###   ########.fr       */
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

static int	ft_word(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1);
	while (s1[i] && ft_word(set, s1[i]) == 1)
		i++;
	while (j > i && ft_word(set, s1[j - 1]) == 1)
		j--;
	new = (char *)malloc((j - i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < j)
		new[k++] = s1[i++];
	new[k] = '\0';
	return (new);
}
