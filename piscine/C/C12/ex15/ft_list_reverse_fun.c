#include "ft_list.h"

static int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		i;
	int		j;
	t_list	*it;
	void	*tmp;

	size = ft_list_size(begin_list);
	i = 0;
	while (i < size - 1)
	{
		j = i;
		it = begin_list;
		while (it && it->next && j < size - 1)
		{
			tmp = it->data;
			it->data = it->next->data;
			it->next->data = tmp;
			it = it->next;
			j++;
		}
		i++;
	}
}
