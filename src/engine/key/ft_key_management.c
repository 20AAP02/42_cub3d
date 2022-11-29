/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:37:16 by rteles            #+#    #+#             */
/*   Updated: 2022/11/27 16:49:00 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_keys.h>
#include <ft_sprites.h>
#include <ft_scenes.h>
#include <ft_scenes_images.h>
#include <ft_sound.h>

int	key_management(void)
{
	(canva())->scene_show[SC_LOGIN].key = 0;
	(canva())->scene_show[SC_MENU].key = key_menu;
	(canva())->scene_show[SC_GAME].key = key_game;
	(canva())->scene_show[SC_PAUSE].key = key_pause;
	return (0);
}
