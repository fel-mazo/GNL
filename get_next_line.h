/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 00:50:17 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/12/22 01:23:21 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

# define BUFF_SIZE 3

int		get_next_line(const int fd, char **line);

#endif
