/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:42:21 by makurek           #+#    #+#             */
/*   Updated: 2024/10/10 15:14:51 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i++] = '\0';
	}
	return (dst);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	len;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len - 1]))
		len--;
	trimmed_str = malloc(len + 1);
	if (!trimmed_str)
		return (NULL);
	ft_strncpy(trimmed_str, s1, len);
	trimmed_str[len] = '\0';
	return (trimmed_str);
}
