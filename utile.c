/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:26:21 by ibenmain          #+#    #+#             */
/*   Updated: 2022/08/11 15:10:59 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	ft_strncmp(char *str1, int i, char *str2)
{
	int	j;

	j = 0;
	while ((str1[i] && str1[i] != '$') || str2[j])
	{
		if (str1[i] != str2[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	j;

	j = 0;
	while (str1[j] || str2[j])
	{
		if (str1[j] != str2[j])
			return (1);
		j++;
	}
	return (0);
}

void	ft_lstadd_back(t_env **alst, t_env *new)
{
	t_env	*ptr;

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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		new = malloc(1);
	else
	{
		if (len > str_len)
			len = str_len;
		new = (char *)malloc((len + 1) * sizeof(char));
		if (!new)
			return (NULL);
		while (i < len)
			new[i++] = s[start++];
	}
	new[i] = '\0';
	return (new);
}
