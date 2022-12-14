/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_life.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:58:01 by rteles            #+#    #+#             */
/*   Updated: 2022/11/28 19:19:06 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

void	ft_lives(void)
{
	t_data	*data;

	data = (canva())->sprite(HEART);
	if (!data)
		return ;
	if ((player())->lives >= 1)
		(canva())->resize(data, ft_aux((engine())->size[X] * 0.03, \
		(engine())->size[Y] * 0.03, (engine())->size[X] * 0.105, \
		(engine())->size[Y] * 0.158));
	if ((player())->lives >= 2)
		(canva())->resize(data, ft_aux((engine())->size[X] * 0.03, \
		(engine())->size[Y] * 0.03, \
		(engine())->size[X] * 0.14, (engine())->size[Y] * 0.158));
	if ((player())->lives >= 3)
		(canva())->resize(data, ft_aux((engine())->size[X] * 0.03, \
		(engine())->size[Y] * 0.03, \
		(engine())->size[X] * 0.175, (engine())->size[Y] * 0.158));
}

void	ft_life_percent_2(int x, double life)
{
	(canva())->color(ft_aux((engine())->size[X] * 0.0001, \
	(engine())->size[Y] * 0.024, (engine())->size[X] * 0.104 + \
	(engine())->size[X] * x, (engine())->size[Y] * 0.107), 0X6b4324);
	(canva())->word((string()).itoa((int)(life * 100)), \
	ft_aux((engine())->size[X] * 0.04, (engine())->size[Y] * 0.025, \
	(engine())->size[X] * 0.1682, (engine())->size[Y] * 0.105), 1);
}

void	ft_life_percent(void)
{
	double	x;
	double	life;
	int		color;

	life = (double)(player())->life / 1000;
	if (life > 0.50)
		color = 0X467527;
	else if (life > 0.25)
		color = 0xe8a620;
	else if (life > 0.10)
		color = 0xf74a28;
	else
		color = 0x8a0904;
	x = life * 0.17;
	(canva())->color(ft_aux((engine())->size[X] * x, (engine())->size[Y] * \
	0.024, (engine())->size[X] * 0.104, (engine())->size[Y] * 0.107), color);
	ft_life_percent_2(x, life);
}

void	ft_fatigue(void)
{
	double	fadigue;

	fadigue = ((player())->fadigue / 100) * 0.17;
	(canva())->color(ft_aux((engine())->size[X] * fadigue, \
	(engine())->size[Y] * 0.01, (engine())->size[X] * 0.104, \
	(engine())->size[Y] * 0.144), 0x2259f0);
	if ((double)(player())->life / 1000 <= 0.5)
		(player())->avatar = (canva())->sprite(AVATAR_2);
	else
		(player())->avatar = (canva())->sprite(AVATAR);
	(canva())->resize((player())->avatar, ft_aux((engine())->size[X] * 0.068, \
	(engine())->size[Y] * 0.08, (engine())->size[X] * 0.024, \
	(engine())->size[Y] * 0.087));
}

void	ft_life(t_scene_img *scene)
{
	(void)scene;
	(canva())->word("WOLF", ft_aux((engine())->size[X] * 0.10, \
	(engine())->size[Y] * 0.03, (engine())->size[X] * 0.1, \
	(engine())->size[Y] * 0.065), 0);
	(canva())->color(ft_aux((engine())->size[X] * 0.077, \
	(engine())->size[Y] * 0.136, (engine())->size[X] * 0.021, \
	(engine())->size[Y] * 0.061), 0X6b4324);
	(canva())->color(ft_aux((engine())->size[X] * 0.07, \
	(engine())->size[Y] * 0.124, (engine())->size[X] * 0.024, \
	(engine())->size[Y] * 0.067), 0xe6be7e);
	(canva())->color(ft_aux((engine())->size[X] * 0.177, \
	(engine())->size[Y] * 0.036, (engine())->size[X] * 0.101, \
	(engine())->size[Y] * 0.101), 0X6b4324);
	(canva())->color(ft_aux((engine())->size[X] * 0.17, \
	(engine())->size[Y] * 0.024, (engine())->size[X] * 0.104, \
	(engine())->size[Y] * 0.107), 0xe6be7e);
	ft_life_percent();
	ft_fatigue();
	ft_lives();
}
