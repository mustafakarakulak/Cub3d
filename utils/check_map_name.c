/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:20:48 by mkarakul          #+#    #+#             */
/*   Updated: 2023/07/04 14:12:55 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_error(int type)
{
	if (type == 1)
		printf("Error wrong map name\n");
	else if (type == 2)
		printf("Error wrong map\n");
	exit(0);
}

int	check_map_name(char *str)
{
	int	i;
	int	fd;

	i = ft_strlen(str) - 1;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	if (str[i] != 'b')
		return (1);
	else if (str[i - 1] != 'u')
		return (1);
	else if (str[i - 2] != 'c')
		return (1);
	else if (str[i - 3] != '.')
		return (1);
	else if (str[i - 4] == '/' || str[i - 4] == 0)
		return (1);
	return (0);
}
