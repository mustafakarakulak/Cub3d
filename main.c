/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:02:29 by mkarakul          #+#    #+#             */
/*   Updated: 2023/08/11 19:33:13 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_control(char *map, int type, t_map *mapes)
{
	if (empty_map(map) && type == 1)
		return (1);
	if (map_space_control(map) && type == 1)
		return (1);
	else if (type == 2)
	{
		if (map_param_check(mapes->fullmap))
			return (1);
	}
	return (0);
}

void	start_mlx(t_map *map)
{
	get_pos_dir(map);
	get_direction(map);
	map->move_speed = 0.15;
	map->rotate_speed = 0.05;
	map->img_width = 64;
	map->img_height = 64;
	map->x_resolution = 1440;
	map->y_resolution = 900;
	map->mlx_ptr = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx_ptr, map->x_resolution,
			map->y_resolution, "Cub3d");
	get_image_data(map);
	map->img_screen = mlx_new_image(map->mlx_ptr, map->x_resolution,
			map->y_resolution);
	map->screen_data = (int *)mlx_get_data_addr(map->img_screen, &map->bpp,
			&map->size_line, &map->endian);
	mlx_loop_hook(map->mlx_ptr, &raycasting, map);
	mlx_hook(map->mlx_win, 2, 0, &key_press, map);
	mlx_hook(map->mlx_win, 17, 0, &key_p, map);
	mlx_loop(map->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_map	*mapes;

	if (argc != 2)
	{
		printf("%s\n", "You must be add map! | ./cub3d maps.cub");
		return (1);
	}
	mapes = malloc(sizeof(t_map) * 1);
	if (check_map_name(argv[1]))
		map_error(1);
	mapes->map_line = get_map(argv[1]);
	if (map_control(mapes->map_line, 1, mapes))
		map_error(2);
	mapes->fullmap = ft_split(mapes->map_line, '\n');
	full_map_space_trim(mapes);
	if (map_control(mapes->map_line, 2, mapes))
		map_error(2);
	mapes->map = malloc(sizeof(char *) * (map_size(mapes->fullmap) + 1));
	fill_map(mapes);
	if (rgb_check(mapes) || file_check(mapes))
		map_error(2);
	map_check(mapes);
	start_mlx(mapes);
	closed_game(mapes);
	return (0);
}
