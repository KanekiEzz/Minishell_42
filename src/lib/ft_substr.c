/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:25:18 by iezzam            #+#    #+#             */
/*   Updated: 2025/02/03 15:25:18 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*empty_str(void)
{
	char	s[2];

	s[0] = -2;
	s[1] = '\0';
	return (ft_strdup(s));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (empty_str());
	if (start == len)
		return (empty_str());
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr = ft_malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
