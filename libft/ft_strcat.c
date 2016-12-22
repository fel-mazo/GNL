/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:11:37 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/13 17:21:54 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*herep;
	size_t	this;

	herep = s1 + ft_strlen((const char *)s1);
	this = ft_strlen(s2);
	herep = ft_memcpy((void *)herep, (const void *)s2, this + 1);
	return (s1);
}
