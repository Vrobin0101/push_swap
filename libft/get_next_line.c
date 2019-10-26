/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:26:31 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/26 11:43:22 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				error_n(char *str, t_file *filedata, char *buffer)
{
	size_t	i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			cpt++;
		i++;
	}
	if (ft_strcmp(buffer, "\n") == 0 || cpt != 0
			|| str[i - 1] == '\n' || str[i] == '\n')
		return (1);
	free(filedata);
	free(str);
	free(buffer);
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

int				end_gnl(t_file *filedata, char *str, char *buffer, char **line)
{
	int i;

	i = 0;
	if (ft_strcmp(str, "") != 0 && !error_n(str, filedata, buffer))
		return (-2);
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
	return (i);
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
	if (end_gnl(filedata, str, buffer, line) == -2)
		return (-2);
	free(str);
	free(buffer);
	return (i);
}
