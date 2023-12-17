/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:23:42 by apaula-l          #+#    #+#             */
/*   Updated: 2023/12/15 10:42:30 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	unsigned int	i;
	char			*dest;

	dest = (char *) malloc(ft_strlen(s) + 1);
	if (dest == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*joint;

	joint = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joint == NULL)
	{
		return (NULL);
	}
	ft_concat_str(joint, s1, s2);
	return (joint);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[len] = '\0';
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	maxlen;

	maxlen = 0;
	while (*s != '\0')
	{
		maxlen++;
		s++;
	}
	return (maxlen);
}

void	ft_concat_str(char *joint, char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		joint[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		joint[i] = s2[j];
		j++;
		i++;
	}
	joint[i] = '\0';
}
