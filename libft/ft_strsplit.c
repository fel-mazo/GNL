/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 09:12:16 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/23 22:13:02 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_word			ft_getword(char const *s, size_t len, size_t b, char c)
{
	t_word	word;
	size_t	start;
	size_t	l;

	start = b;
	l = 0;
	word.start = b;
	word.len = l;
	if (!s)
		return (word);
	while (start < len && s[start] == c)
		start++;
	word.start = (unsigned int)start;
	while (start < len && s[start] != c)
	{
		l++;
		start++;
	}
	word.len = l;
	return (word);
}

static unsigned int		ft_count(char const *s, char c)
{
	size_t			len;
	size_t			i;
	unsigned int	count;

	if (!s)
		return (0);
	len = ft_strlen((const char *)s);
	i = 1;
	count = 0;
	while (i <= len)
	{
		if (s[i - 1] != c && (s[i] == c || s[i] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static	unsigned int	*ft_info(char const *s, char c)
{
	unsigned int	*ret;

	if (!s)
		return (NULL);
	if (!(ret = (unsigned int *)malloc(sizeof(unsigned int) * 2)))
		return (NULL);
	ret[0] = (unsigned int)ft_strlen((const char *)s);
	ret[1] = ft_count(s, c);
	return (ret);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**ret;
	unsigned int	*info;
	size_t			b;
	size_t			index;
	t_word			w;

	if (!s)
		return (NULL);
	if (!(info = ft_info(s, c)))
		return (NULL);
	if (!(ret = (char **)ft_memalloc((info[1] + 1) * sizeof(char **))))
		return (NULL);
	index = 0;
	b = 0;
	while (info[1]--)
	{
		w = ft_getword(s, info[0], b, c);
		if (!(ret[index++] = ft_strsub(s, w.start, w.len)))
			return (NULL);
		b = (size_t)w.start + w.len;
	}
	free(info);
	info = NULL;
	return (ret);
}
