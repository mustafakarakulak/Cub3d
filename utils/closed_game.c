/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:11:48 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/23 19:22:55 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	closed_game(t_map *mapes)
{
	free_map(mapes->fullmap);
	free_map(mapes->map);
	free_map(mapes->tmp_map);
	free(mapes->map_line);
	free(mapes->no);
	free(mapes->so);
	free(mapes->we);
	free(mapes->ea);
	free(mapes->f);
	free(mapes->c);
}
