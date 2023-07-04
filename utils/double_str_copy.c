/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_str_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:19:41 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/23 19:23:02 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**double_str_copy(t_map *mapes)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * (map_size(mapes->fullmap) + 1));
	while (mapes->map[i])
	{
		map[i] = ft_strdup(mapes->map[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}
