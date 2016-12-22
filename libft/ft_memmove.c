/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 09:55:52 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/13 10:20:27 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp;

	tmp = ft_memalloc(len);
	if (tmp == NULL)
		return (dst);
	tmp = ft_memcpy(tmp, src, len);
	dst = ft_memcpy(dst, (const void *)tmp, len);
	free(tmp);
	return (dst);
}
