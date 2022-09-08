/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:39:56 by amaria-m          #+#    #+#             */
/*   Updated: 2022/09/08 12:21:59 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

t_list	*ft_map_check(char *filename)
{
	int		fd;
	char	*str;
	t_list	*map;
	t_list	*line;

	if (string().len(filename) < 5)
		return (NULL);
	if (!string().cmp(filename + string().len(filename) - 4, ".cub"))
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = get_next_line(fd);
	map = list().new(NULL);
	printf("bla\n");
	return (NULL);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_map_check(argv[1]);
	return (0);
}
