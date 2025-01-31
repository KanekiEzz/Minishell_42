/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:15:25 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/27 12:58:06 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*skip_delimiters(char *str, const char *delim)
{
	while (*str && ft_strchr(delim, *str))
		str++;
	return (str);
}

static char	*find_token_end(char *str, const char *delim)
{
	while (*str && !ft_strchr(delim, *str))
		str++;
	return (str);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*next;
	char		*start;
	char		*end;

	if (str != NULL)
		next = str;
	if (next == NULL)
		return (NULL);
	start = skip_delimiters(next, delim);
	if (*start == '\0')
	{
		next = NULL;
		return (NULL);
	}
	end = find_token_end(start, delim);
	if (*end != '\0')
	{
		*end = '\0';
		next = end + 1;
	}
	else
		next = NULL;
	return (start);
}
