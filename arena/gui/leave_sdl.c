/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave_sdl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:45:31 by roduquen          #+#    #+#             */
/*   Updated: 2019/09/01 12:47:22 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui.h>

static void	leave_ttf(t_gui *data)
{
	int			i;
	int			j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 256)
		{
			if (data->byte_s[j][i])
				SDL_DestroyTexture(data->byte_s[j][i]);
			if (data->byte[j][i])
				SDL_FreeSurface(data->byte[j][i]);
			j++;
		}
		i++;
	}
	if (data->font[0])
		TTF_CloseFont(data->font[0]);
	if (data->font[1])
		TTF_CloseFont(data->font[1]);
	TTF_Quit();
}

int			leave_sdl(t_gui *data, int type)
{
	leave_ttf(data);
	if (data->texture)
		SDL_DestroyTexture(data->texture);
	if (data->renderer)
		SDL_DestroyRenderer(data->renderer);
	if (data->window)
		SDL_DestroyWindow(data->window);
	SDL_Quit();
	data->running = SDL_TRUE;
	data->pause = -1;
	return (type);
}
