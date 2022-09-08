/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:32:11 by amaria-m          #+#    #+#             */
/*   Updated: 2022/09/08 18:32:52 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

t_list	*ft_map_check(char *filename)
{
	int		fd;
	char	*str;
	t_list	*map;

	if (string().len(filename) < 5)
		return (NULL);
	if (!string().cmp(filename + string().len(filename) - 4, ".cub"))
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = get_next_line(fd);
	map = list().new(NULL);
	map = list().set(map, str, 0);
	str = get_next_line(fd);
	while (str)
	{
		map = list().add(map, str);
		str = get_next_line(fd);
	}
	close(fd);
	return (map);
}
