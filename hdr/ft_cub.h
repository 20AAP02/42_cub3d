/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:56:15 by amaria-m          #+#    #+#             */
/*   Updated: 2022/09/07 20:26:53 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB_H
# define FT_CUB_H

# include <ft_string.h>
# include <ft_array.h>
# include <ft_list.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h> // open, close, read ...

# include <stdio.h> // printf

# define BUFFERSIZE 9999

char	*get_next_line(int fd);

#endif