/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:12:27 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/24 17:03:15 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		res;
	size_t	i;
	char	*s;
	int		p;

	s = ft_strtrimwhites(str);
	i = 0;
	res = 0;
	p = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		p = s[i] == '-' ? -1 : 1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		res += p > 0 ? (int)(s[i] - '0') : -1 * (int)(s[i] - '0');
		i++;
		if (!ft_isdigit(s[i]))
			return (res);
		res = res * 10;
	}
	return (0);
}
