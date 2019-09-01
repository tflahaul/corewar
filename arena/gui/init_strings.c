/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:38:46 by roduquen          #+#    #+#             */
/*   Updated: 2019/09/01 12:55:33 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui.h>
#include <libft.h>

static void	create_string_position(t_gui *data)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	x = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			data->pos[x][0] = 16 + j * 27;
			data->pos[x][1] = 80 + i * 21;
			x++;
			j++;
		}
		i++;
	}
}

static int	textures_and_surfaces(t_gui *data, char byte[3], char *base
	, int count[4])
{
	count[1] = -1;
	while (++count[1] < 16)
	{
		byte[0] = base[count[0]];
		byte[1] = base[count[1]];
		data->byte[count[2]][count[3]] = TTF_RenderText_Blended(
				data->font[0], byte, data->color[count[3]]);
		if (!data->byte[count[2]][count[3]])
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION
					, "Couldn't load strings: %s", SDL_GetError());
			return (EXIT_FAILURE);
		}
		if (!(data->byte_s[count[2]][count[3]] =
					SDL_CreateTextureFromSurface(data->renderer
						, data->byte[count[2]][count[3]])))
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION
					, "Couldn't create strings: %s", SDL_GetError());
			return (EXIT_FAILURE);
		}
		count[2]++;
	}
	return (EXIT_SUCCESS);
}

int			create_every_strings(t_gui *data, char *base)
{
	int			count[4];
	char		byte[3];

	byte[2] = 0;
	count[3] = -1;
	while (++count[3] < 5)
	{
		count[0] = -1;
		count[2] = 0;
		while (++count[0] < 16)
		{
			if (textures_and_surfaces(data, byte, base, count) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
	}
	create_string_position(data);
	return (EXIT_SUCCESS);
}
