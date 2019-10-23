/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:26:31 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/23 16:48:53 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				check_next(char *str)
{
	if ((ft_strncmp(str, "pa", 2) == 0)
			|| (ft_strncmp(str, "pb", 2) == 0)
			|| (ft_strncmp(str, "sa", 2) == 0)
			|| (ft_strncmp(str, "sb", 2) == 0)
			|| (ft_strncmp(str, "ss", 2) == 0)
			|| (ft_strncmp(str, "ra", 2) == 0)
			|| (ft_strncmp(str, "rb", 2) == 0)
			|| (ft_strncmp(str, "rra", 3) == 0)
			|| (ft_strncmp(str, "rrb", 3) == 0)
			|| (ft_strncmp(str, "rr", 2) == 0)
			|| (ft_strncmp(str, "sha", 3) == 0)
			|| (ft_strncmp(str, "shb", 3) == 0)
			|| (ft_strncmp(str, "shh", 3) == 0))
		return (1);
	return (0);
}

static	char	*ft_half(char **str)
{
	int i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\0')
		return (NULL);
	(*str)[i] = '\0';
	return (ft_strdup((*str) + i + 1));
}

static	t_file	*ft_get_file_data(int fd, t_file **head)
{
	t_file	*temp;
	t_file	*previous;

	previous = NULL;
	temp = *head;
	while (temp != NULL)
	{
		if (temp->fd == fd)
			return (temp);
		previous = temp;
		temp = temp->next;
	}
	if (!(temp = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	temp->fd = fd;
	temp->reste = NULL;
	temp->next = NULL;
	if (previous != NULL)
		previous->next = temp;
	else
		*head = temp;
	return (temp);
}

int				get_next_line(int fd, char **line)
{
	static t_file	*head;
	t_file			*filedata;
	char			*str;
	char			*buffer;
	int				i;

	filedata = ft_get_file_data(fd, &head);
	str = ft_strnew(0);
	if (filedata->reste)
		str = ft_strjoinf(&str, &filedata->reste, 3);
	if (!(buffer = ft_strnew(BUFF_SIZE)) || fd < 0)
		return (-1);
	while (!(ft_strchr(str, '\n')) && (i = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (ft_strcmp(buffer, "\n\0") == 0)
			break ;
		str = ft_strjoinf(&str, &buffer, 1);
		ft_bzero(buffer, BUFF_SIZE);
	}
	filedata->reste = ft_half(&str);
	*line = ft_strdup(str);
	i = (ft_strchr(str, '\n') == 0 && (i > 0 || ft_strlen(*line) > 0)) ? 1 : 0;
	if (check_next(str) == 0)
	{
		free(filedata);
		free(filedata->reste);
		if (ft_strcmp(buffer, "\n\0") == 0)
		{
			free(str);
			free(buffer);
			return (-2);
		}
	}
	free(str);
	free(buffer);
	return (i);
}
