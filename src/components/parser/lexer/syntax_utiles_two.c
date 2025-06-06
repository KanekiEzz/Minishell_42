/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utiles_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:23:16 by yaajagro          #+#    #+#             */
/*   Updated: 2025/04/23 15:24:53 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/parser.h"

int	valid_next(t_TokenType type)
{
	return (type == COMMAND || type == RIGHT_RED || type == LEFT_RED || \
		type == HERDOC || type == APPEND);
}

int	check_append(t_node *data)
{
	t_node	*prv;

	prv = NULL;
	while (data)
	{
		if (data->type == HERDOC)
		{
			if (!prv)
				return (1);
			if (!data->next)
				return (1);
			if (data->next->type != COMMAND || prv->type != COMMAND)
				return (1);
		}
		prv = data;
		data = data->next;
	}
	return (0);
}

char	*skip_spaces(char *s)
{
	if (!s)
		return (NULL);
	while (*s && ft_isspace(*s))
		s++;
	return (s);
}

void	copy_word(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[len] = '\0';
}
