/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 01:36:11 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/12/22 08:31:01 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*new(int fd)
{
	t_gnl	*ret;

	ret = (t_gnl *)malloc(sizeof(t_gnl));
	ret->fd = fd;
	ret->keep = ft_strnew(0);
	ret->next = NULL;
	return (ret);
}

static t_gnl	*get(t_gnl *head, int fd)
{
	while (head)
	{
		if (head->fd == fd)
			return (head);
		head = head->next;
	}
	head = new(fd);
	return (head);
}

static int		more(t_gnl *f, char *buff)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(f->keep);
	len2 = ft_strlen(buff);
	ft_memrealloc(f->keep, len1 + 1, len1 + len2 + 1);
	ft_strncat(f->keep, buff, len2);
	return (ft_strchri(f->keep, '\n'));
}

static void		less(t_gnl *f)
{
	char	*tmp;
	size_t	len;
	int		here;

	tmp = f->keep;
	len = ft_strlen(f->keep);
	here = ft_strchri(f->keep, '\n');
	if (here >= 0)
		f->keep = ft_strsub(f->keep, ft_strchri(f->keep, '\n'), len);
	else
		f->keep = ft_strnew(0);
	free(tmp);
}

int				get_next_line(const int fd, char **line)
{
	int				r[3];
	char			buff[BUFF_SIZE + 1];
	int				here;
	static t_gnl	*head = NULL;
	t_gnl			*f;

	r[1] = 0;
	r[0] = 1;
	if (fd < 0 || !line)
		return (-1);
	*line = ft_strnew(0);
	head = (head == NULL) ? new(fd) : head;
	f = get(head, fd);
	r[2] = ft_strlen(f->keep);
	here = -1;
	while (here < 0 && r[0] > 0)
	{
		r[0] = read(fd, buff, BUFF_SIZE);
		r[1] += r[0];
		buff[r[0]] = '\0';
		here = more(f, buff);
	}
	*line = ft_strsub(f->keep, 0, here < 0 ? ft_strlen(f->keep) : here - 1);
	less(f);
	return (r[0] < 0 ? -1 : r[1] || r[2]);
}
