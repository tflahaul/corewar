/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:26:25 by roduquen          #+#    #+#             */
/*   Updated: 2019/09/02 09:55:40 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui.h>
#include <libft.h>

static void	init_color(t_gui *data)
{
	data->color[0].r = 185;
	data->color[0].g = 185;
	data->color[0].b = 185;
	data->color[0].a = 0;
	data->color[1].r = 225;
	data->color[1].g = 20;
	data->color[1].b = 20;
	data->color[1].a = 0;
	data->color[2].r = 20;
	data->color[2].g = 20;
	data->color[2].b = 225;
	data->color[2].a = 0;
	data->color[3].r = 20;
	data->color[3].g = 225;
	data->color[3].b = 20;
	data->color[3].a = 0;
	data->color[4].r = 200;
	data->color[4].g = 84;
	data->color[4].b = 179;
	data->color[4].a = 0;
}

static int	init_font(t_gui *data)
{
	if (TTF_Init() < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize TTF: %s"
				, SDL_GetError());
		return (EXIT_FAILURE);
	}
	if (!(data->font[0] = TTF_OpenFont("arena/gui/img/monofonto.ttf", 17)))
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create font: %s"
				, SDL_GetError());
		return (EXIT_FAILURE);
	}
	if (!(data->font[1] = TTF_OpenFont("arena/gui/img/helvetica.ttf", 40)))
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create font: %s"
				, SDL_GetError());
		return (EXIT_FAILURE);
	}
	return (create_every_strings(data, "0123456789ABCDEF"));
}

static int	init_texture(t_gui *data)
{
	if (!(data->texture = SDL_CreateTexture(data->renderer
					, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING
					, WIDTH, HEIGHT)))
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture: %s"
				, SDL_GetError());
		return (EXIT_FAILURE);
	}
	if (!(data->bmp = SDL_LoadBMP("arena/gui/img/graphic.bmp")))
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create bmp: %s"
				, SDL_GetError());
		return (EXIT_FAILURE);
	}
	data->speed = 1;
	init_color(data);
	return (init_font(data));
}

int			gui(t_gui *data)
{
	ft_memset(data, 0, sizeof(t_gui));
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s"
				, SDL_GetError());
		return (leave_sdl(data, 1));
	}
	if (!(data->window = SDL_CreateWindow("corewar"
					, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH
					, HEIGHT, SDL_WINDOW_FULLSCREEN)))
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s"
				, SDL_GetError());
		return (leave_sdl(data, 1));
	}
	if (!(data->renderer = SDL_CreateRenderer(data->window, -1
					, SDL_RENDERER_PRESENTVSYNC)))
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION
				, "Couldn't create renderer: %s", SDL_GetError());
		return (leave_sdl(data, 1));
	}
	if (init_texture(data))
		return (leave_sdl(data, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
