/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/11/28 19:30:17 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>

static void	colors_floor_ceilling(char **floor, char **ceilling)
{
	char	r;
	char	g;
	char	b;

	r = (string()).atoi(floor[0]);
	g = (string()).atoi(floor[1]);
	b = (string()).atoi(floor[2]);
	(engine())->color[FLOOR] = ft_trgb(0, r, g, b);
	r = (string()).atoi(ceilling[0]);
	g = (string()).atoi(ceilling[1]);
	b = (string()).atoi(ceilling[2]);
	(engine())->color[CEILLING] = ft_trgb(0, r, g, b);
}

void	new_engine(t_all *all, int larg, int alt)
{
	(engine())->ptr = mlx_init();
	if (!engine()->ptr)
		return ;
	(engine())->size[X] = larg;
	(engine())->size[Y] = alt;
	(engine())->max[X] = -1;
	(engine())->max[Y] = -1;
	(engine())->win = mlx_new_window((engine())->ptr, (engine())->size[X], \
		(engine())->size[Y], "WOLF EAT PIG'S");
	colors_floor_ceilling(all->file->f, all->file->c);
	(engine())->map = 0;
	(engine())->start_time = time_current();
	(engine())->time = 0;
	(engine())->count = -1;
	(engine())->sprt_for_sec = 60;
	(engine())->pause = 0;
	(engine())->menu = 1;
	(engine())->object = 0;
	(engine())->enemies = 0;
	new_key();
	new_sound();
	new_canva();
}

t_engine	*engine(void)
{
	static t_engine	e;

	return (&e);
}
