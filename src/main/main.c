/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:39:56 by amaria-m          #+#    #+#             */
/*   Updated: 2022/09/12 18:45:43 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

typedef struct s_map_info
{
	t_list	*map;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	**F;
	char	**C;
}			t_map;

void	ft_init_map_info(t_map *map)
{
	map->map = NULL;
	map->NO = NULL;
	map->SO = NULL;
	map->WE = NULL;
	map->EA = NULL;
	map->F = NULL;
	map->C = NULL;
}

int		ft_check_map_info(t_map *map)
{
	if (!map->map)
		return (0);
	if (!map->NO)
		return (0);
	if (!map->SO)
		return (0);
	if (!map->WE)
		return (0);
	if (!map->EA)
		return (0);
	if (!map->F)
		return (0);
	if (!map->C)
		return (0);
	return (1);
}

void *ft_print_lst(void *ptr)
{
	printf("%s", (char*)ptr);
	return (ptr);
}

t_list	*ft_del_w_spc(t_list *map)
{
	int		i;
	char	*str;

	if (!map)
		return (NULL);
	i = -1;
	while (list().get(map, ++i))
	{
		str = string().trim(list().get(map, i));
		if (!str || !string().len(str))
			map = list().rmv(map, i--);
		free(str);
	}
	return (map);
}

int	ft_check_line(char *line)
{
	if (string().contains(line, "NO") == 1)
		return (1);
	if (string().contains(line, "SO") == 1)
		return (2);
	if (string().contains(line, "WE") == 1)
		return (3);
	if (string().contains(line, "EA") == 1)
		return (4);
	if (string().contains(line, "F") == 1)
		return (5);
	if (string().contains(line, "C") == 1)
		return (6);
	else
		return (0);
}

int		ft_is_path(char *str)
{
	int	i;
	int fd;

	if (ft_check_line(str) < 1 || ft_check_line(str) > 4)
		return (0);
	i = 0;
	while (str && str[i] && str[i] >= 'A' && str[i] <= 'Z')
		i++;
	while (str && str[i] && string().is_spc(str[i]))
		i++;
	str = &str[i];
	fd = open(str, O_RDONLY);
	if (!fd)
		return (0);
	close(fd);
	return (i);
}

int		ft_is_color(char *str)
{
	int	i;

	if (ft_check_line(str) < 5)
		return (0);
	i = 0;
	if (str && str[i] && str[i] >= 'A' && str[i] <= 'Z')
		i++;
	while (str && str[i] && string().is_spc(str[i]))
		i++;
	str = &str[i];
	if (*str >= '0' && *str <= '9' && string().atoi(str) <= 255 && string().atoi(str) >= 0)
		str = string().strnstr(str, ",", string().len(str)) + 1;
	else
		return (0);
	if (*str >= '0' && *str <= '9' && string().atoi(str) <= 255 && string().atoi(str) >= 0)
		str = string().strnstr(str, ",", string().len(str)) + 1;
	else
		return (0);
	if (*str >= '0' && *str <= '9' && string().atoi(str) <= 255 && string().atoi(str) >= 0)
		return (i);
	else
		return (0);
}

void	ft_choose_inf_elm(t_map *map, char *line)
{
	char	*str;

	str = string().cpy(line);
	if (ft_check_line(line) == 1)
		map->NO = str + ft_is_path(str);
	if (ft_check_line(line) == 2)
		map->SO = str + ft_is_path(str);
	if (ft_check_line(line) == 3)
		map->WE = str + ft_is_path(str);
	if (ft_check_line(line) == 4)
		map->EA = str + ft_is_path(str);
	if (ft_check_line(line) == 5)
		map->F = string().split(str + ft_is_color(str), ",");
	if (ft_check_line(line) == 6)
		map->C = string().split(str + ft_is_color(str), ",");
}

t_map	ft_checker(int argc, char **argv)
{
	t_map	map;
	char	*str;
	int		i;

	ft_init_map_info(&map);
	if (argc == 1)
		return (map);
	map.map = ft_read_map(argv[1]);
	i = -1;
	while (list().get(map.map, ++i))
	{
		str = string().trim(list().get(map.map, i));
		if (string().len(str) && ft_check_line(str) == 0)
		{
			free(str);
			break ;
		}
		if (string().len(str) && ft_is_path(str))
			ft_choose_inf_elm(&map, str);
		else if (string().len(str) && ft_is_color(str))
			ft_choose_inf_elm(&map, str);
		else if (string().len(str))
			break ;
		free(str);
	}
	map.map = ft_del_w_spc(map.map);
	return (map);
}

int	main(int argc, char **argv)
{
	t_map map;

	map = ft_checker(argc, argv);
	list().free(map.map);
	return (0);
}
