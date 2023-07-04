/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:19:52 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/23 19:23:15 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	hex_to_decimal(t_map *mapes)
{
	char	**rgb;

	rgb = ft_split(mapes->f, ',');
	mapes->f_int = rgb_to_int(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
			ft_atoi(rgb[2]));
	free_map(rgb);
	rgb = ft_split(mapes->c, ',');
	mapes->c_int = rgb_to_int(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
			ft_atoi(rgb[2]));
	free_map(rgb);
}
