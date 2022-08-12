/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 20:07:12 by ibenmain          #+#    #+#             */
/*   Updated: 2022/08/12 20:57:10 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_print_error(void)
{
	printf ("Syntaxe error\n");
	return (NULL);
}

char	*ft_check_pipe(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '|' || str[ft_strlen(str) - 1] == '|')
		return (ft_print_error());
	else
	{
		while (str[i])
		{
			if (str[i] == '|' && (str[i + 1] == '>' || str[i + 2] == '>'
					|| str[i + 1] == '<' || str[i + 2] == '<'))
				return (ft_print_error());
			i++;
		}
	}
	return (str);
}

char	*ft_check_all_error(char *str)
{
	str = ft_check_pipe(str);
	return (str);
}
