#include "lem_in.h"

int			is_int(char *s)
{
	char	*new;
	int		res;

	new = ft_itoa(ft_atoi(s));
	res = ft_strcmp(new, s);
	free(new);
	return (!res);
}

int			check_comment(char *s)
{
	char	**parse;

	if (!s)
		return (0);
	if (!ft_strcmp(s, "##start"))
		return (2);
	if (!ft_strcmp(s, "##end"))
		return (3);
	if (*s == '#')
		return (1);
	if (ft_strchr(s, ' ') && (parse = ft_strsplit(s, ' ')))
	{
		if (!parse[0] || parse[0][0] == 'L' || !parse[1] ||
			!is_int(parse[1]) || !parse[2] ||
			!is_int(parse[2]) || parse[3])
			return (free_2d(parse, 0));
		return (free_2d(parse, -1));
	}
	if (ft_strchr(s, '-') && (parse = ft_strsplit(s, '-')))
	{
		if (!parse[0] || !parse[1] || parse[2])
			return (free_2d(parse, 0));
		return (free_2d(parse, -2));
	}
	return (0);
}

int			room_exist(char *line, t_lst *list, int stat)
{
	int		len;

	if (!stat)
	{
		len = ft_strlen(line);
		while (list)
		{
			if (!ft_strncmp(line, list->one_line, len))
				return (1);
			list = list->next;
		}
	}
	else if (stat)
	{
		len = ft_strchr(line, ' ') - line;
		while (list)
		{
			if (!ft_strncmp(line, list->one_line, len + 1) ||
				!ft_strcmp(line + len, ft_strchr(list->one_line, ' ')))
				return (1);
			list = list->next;
		}
	}
	return (0);
}

int			link_n_ok(char *line, t_lst *rms, t_lst *links)
{
	char	*l;
	char	*ll;

	l = ft_strchr(line, '-');
	*l = '\0';
	if (!ft_strcmp(line, l + 1) || !room_exist(line, rms, 0) ||
		!room_exist(l + 1, rms, 0))
		return (1 + 0 * (*l = '-'));
	while (links)
	{
		ll = ft_strchr(links->one_line, '-');
		*ll = '\0';
		if (!room_exist(links->one_line, rms, 0) || !room_exist(ll + 1, rms, 0))
			return (1);
		if ((!ft_strcmp(line, links->one_line) && !ft_strcmp(l + 1, ll + 1))
			|| (!ft_strcmp(line, ll + 1) && !ft_strcmp(l + 1, links->one_line)))
		{
			*ll = '-';
			*l = '-';
			return (1);
		}
		*ll = '-';
		links = links->next;
	}
	return (!(*l = '-'));
}