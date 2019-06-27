#include "lem_in.h"

void		add_elem(char *line, t_lst **lst)
{
	t_lst	*new;

	new = ft_memalloc(sizeof(t_lst));
	new->next = *lst;
	new->line = line;
	*lst = new;
}

void		add_room(char **table, t_rooms **rooms)
{
	t_rooms	*new;

	new = ft_memalloc(sizeof(t_rooms));
	if (valid_name(table[0]))
		new->name = table[0];
	new->x = is_integer(table[1]);
	new->y = is_integer(table[2]);
	new->next = *rooms;
	*rooms = new;
}

void		add_link(char **table, t_links **links)
{
	t_links	*new;

	new = ft_memalloc(sizeof(t_links));
	new->a = table[0];
	new->b = table[1];
	new->next = *links;
	*links = new;
}

void		push_elem(char *line, t_lst **lst)
{
	t_lst	*p;
	t_lst	*new;

	p = *lst;
	if (!p)
	{
		*lst = ft_memalloc(sizeof(t_lst));
		(*lst)->next = NULL;
		(*lst)->line = line;
	}
	else
	{
		while (p->next)
			p = p->next;
		new = ft_memalloc(sizeof(t_lst));
		new->next = NULL;
		new->line = line;
		p->next = new;
	}
}
