/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:32:11 by amaria-m          #+#    #+#             */
/*   Updated: 2022/09/12 15:25:40 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

t_list	*ft_read_map(char *filename)
{
	int		fd;
	char	*str;
	t_list	*map;

	map = NULL;
	if (string().len(filename) < 5)
		return (map);
	if (!string().cmp(filename + string().len(filename) - 4, ".cub"))
		return (map);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (map);
	str = get_next_line(fd);
	while (str)
	{
		if (!map)
			map = list().new(str);
		else
			list().add(map, str);
		str = get_next_line(fd);
	}
	close(fd);
	return (map);
}
