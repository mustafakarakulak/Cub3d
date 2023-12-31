/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_space_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:26:08 by mkarakul          #+#    #+#             */
/*   Updated: 2023/07/04 13:26:08 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_space_control(char *map)
{
	int	i;
	int	mapsize;

	i = 0;
	mapsize = ft_strlen(map);
	while (i < mapsize && map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			i++;
			while (map[i] == ' ')
				i++;
			if (map[i] == '\n')
				i++;
			if (map[i] == '1' || map[i] == '0')
			{
				i--;
				while (map[++i])
					if (map[i] == '\n' && map[i + 1] == '\n')
						return (1);
			}
		}
		i++;
	}
	return (0);
}

int	empty_map(char *map)
{
	int	i;

	i = 0;
	if (!map)
		return (1);
	while (map[i])
	{
		if (map[i] != ' ' && map[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
