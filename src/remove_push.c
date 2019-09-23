#include "../inc/checker.h"

int		size_list(t_string *list)
{
	int i;

	i = 0;
	while (list->next != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	remove_push(t_string *list, int pb)
{
	int			len;
	t_string	*tmp;
	int			i;
	int			pa;

	i = 0;
	pa = pb;
	len = size_list(list);
	pb *=2;
	tmp = list;
	while (i + pb < len && tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	if (ft_strcmp(tmp->s, "pa") != 0)
		return;
	/*
	printf("tmp vaut %s\n", tmp->s);
	printf("tmp next vaut %s\n", tmp->next->s);
	printf("tmp next next vaut %s\n", tmp->next->next->s);
	printf("tmp next next next vaut %s\n", tmp->next->next->next->s);
	printf("tmp next next next next vaut %s\n", tmp->next->next->next->next->s);
	printf("tmp next next next next next vaut %s\n", tmp->next->next->next->next->next->s);
	printf("tmp next next next next next next vaut %s\n", tmp->next->next->next->next->next->next->s);
	*/
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		list_remove(list, i);
	}
}
