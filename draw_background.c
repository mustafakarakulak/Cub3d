/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:02:21 by mkarakul          #+#    #+#             */
/*   Updated: 2023/07/04 14:54:36 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->x_resolution)
	{
		y = -1;
		while (++y < map->y_resolution / 2)
			map->screen_data[y * map->x_resolution + x]
				= map->c_int;
		x++;
	}
	x = 0;
	y = map->y_resolution / 2;
	while (x < map->x_resolution && y < map->y_resolution)
	{
		map->screen_data[y * map->x_resolution + x]
			= map->f_int;
		x++;
		if (x == map->x_resolution)
		{
			y++;
			x = 0;
		}
	}
}

int	raycasting(t_map *map)
{
	int	x;

	x = 0;
	draw_background(map);
	while (x < map->x_resolution)
	{
		map->camera_x = 2 * x / (double)map->x_resolution - 1;
		map->raydir_x = map->dir_x + map->fov_x * map->camera_x;
		map->raydir_y = map->dir_y + map->fov_y * map->camera_x;
		map->map_x = (int)map->pos_x;
		map->map_y = (int)map->pos_y;
		map->delta_dist_x = fabs(1 / map->raydir_x);
		map->delta_dist_y = fabs(1 / map->raydir_y);
		map->hit = 0;
		calculate_step(map);
		hit_check(map);
		calculate_distance_of_ray(map);
		map->tex_pos = (map->draw_start - map->y_resolution
				/ 2 + map->line_height / 2) * map->step;
		set_screen_data(map, x);
		x++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->img_screen, 0, 0);
	return (0);
}
