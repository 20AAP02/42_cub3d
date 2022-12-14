/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:14:54 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/28 18:25:14 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYCASTER_H
# define FT_RAYCASTER_H

typedef struct s_data	t_data;
typedef struct s_object	t_object;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}			t_player;

typedef struct s_view
{
	double	plane_x;
	double	plane_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}			t_view;

typedef struct s_algorithm
{
	int		x;
	int		y;
	int		w;
	double	h;
	double	cam_x;
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		map_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	perp_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		ln_hgt;
	int		draw_str;
	int		draw_end;
	int		texnum;
	double	texpos;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	int		tex_wdh;
	int		tex_hgt;
	int		color;
	int		check;
	int		percent;
	double	*z_buffer;
}			t_alg;

typedef struct s_alg_floor
{
	int		y;
	int		x;
	int		h;
	int		w;
	float	ray_x0;
	float	ray_y0;
	float	ray_x1;
	float	ray_y1;
	int		p;
	float	posz;
	float	rowdist;
	float	stepx;
	float	stepy;
	float	floorx;
	float	floory;
	int		cellx;
	int		celly;
	int		tx;
	int		ty;
	int		flrtex;
	int		c_tex;
	int		color;
	t_data	**data;
}			t_alg_fl;

typedef struct s_sprite
{
	int		len;
	double	x;
	double	y;
	double	udiv;
	double	vdiv;
	double	vmove;
	t_data	*texture;
}			t_spr;

typedef struct s_sprites_values
{
	int		sprite_order[1000];
	double	sprite_dist[1000];
	double	sprite_x;
	double	sprite_y;
	double	invdet;
	double	transform_x;
	double	transform_y;
	int		sprite_scrn_x;
	int		sprite_hgt;
	int		draw_str_y;
	int		draw_end_y;
	int		sprite_wdt;
	int		draw_str_x;
	int		draw_end_x;
	int		stripe;
	int		tex_x;
	int		y;
	int		d;
	int		tex_y;
	int		color;
	double	udiv;
	double	vdiv;
	double	v_move;
	int		i;
	double	*buffer;
	t_spr	*sprite;
}			t_spr_vls;

typedef struct s_caster
{
	t_view		view;
	t_player	player;
	t_alg		alg;
}				t_caster;

// SPRITES
void	ft_ray_sprites(double *buffer, t_view *view, t_spr *sprite);
void	ft_sort_sprites(int *order, double *dist, int amount);
void	ft_print_stripe(t_spr_vls *copy, int i, int vmovescreen, t_view *view);
t_spr	*ft_setup_sprites(t_object *objs);

// FLOOR
void	ft_ray_floor(t_view *view, t_alg_fl a);

// UTILS
int		ft_linear_gradient(int colors[2], float percent);
float	ft_convert_time(double time, int n);
int		ft_setup_ray_imgs(t_data **data);
int		ft_choose_arr0(void);
t_spr	*ft_setup_sprites(t_object *objs);
int		ft_return_tex_x(t_spr_vls	a, int i);
void	ft_color_strip_y(t_spr_vls a, t_view *view, int i);
int		ft_objects_len(t_object *sprites);
void	ft_choose_spr_size(t_spr *sprite, t_object *obj);
float	ft_conv_t_block(int t, int t2, int n, int *past_value);

#endif
