#include "lem_in.h"

void		ants_distribution(t_pathkit paths, int ants)
{
	int		i;
	int		j;
	int		sum;
	int		steps;

	j = 0;
	sum = 0;
	while (j < paths.len)
		sum += paths.paths[j++].len;
	steps = ((sum + ants) / paths.len) - 1;
	i = 0;
	sum = 0;
	while (i < paths.len)
	{
		paths.paths[i].ants = steps - paths.paths[i].len + 1;
		sum += paths.paths[i++].ants;
	}
	ants -= sum;
	while (ants > 0)
		paths.paths[ants-- - 1].ants++;
}

void		set_squads(t_pathkit paths)
{
	int		i;
	int		range;

	i = 0;
	range = 1;
	while (i < paths.len)
	{
		paths.paths[i].index = range;
		range += paths.paths[i++].ants;
	}
}

void		push_squads(t_pathkit paths)
{
	int		i;
	int		move;
	int		limit;

	move = 1;
	limit = paths.paths[0].len + paths.paths[0].ants - 1;
	while (move <= limit)
	{
		i = -1;
		while (++i < paths.len)
			print_steps(paths, move, i, paths.paths[i].index);
		ft_printf("\n");
		move++;
	}
}

void		push_ants(t_pathkit paths, int ants)
{
	ants_distribution(paths, ants);
	set_squads(paths);
	push_squads(paths);
}