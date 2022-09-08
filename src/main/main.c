/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:39:56 by amaria-m          #+#    #+#             */
/*   Updated: 2022/09/08 18:58:21 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void *ft_cp_lst(void *ptr)
{
	printf("%s", (char*)ptr);
	return (ptr);
}

t_list	*ft_checker(int argc, char **argv)
{
	t_list *map;

	if (argc > 1)
		map = ft_map_check(argv[1]);
	else
		return (NULL);
}

int	main(int argc, char **argv)
{
	t_list *map;

	map = ft_checker(argc, argv);
	if (!map)
		return (1);
	list().free(map);
	return (0);
}
