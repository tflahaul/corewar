/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <roduquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:54:04 by roduquen          #+#    #+#             */
/*   Updated: 2019/08/27 17:00:32 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arena.h>
#include <arena_process.h>
#include <gui.h>

static int	leave_sdl(t_gui *data, int type)
{
	if (data->font)
		TTF_CloseFont(data->font);
	TTF_Quit();
	if (data->arn_texture)
		SDL_DestroyTexture(data->arn_texture);
	if (data->texture)
		SDL_DestroyTexture(data->texture);
	if (data->renderer)
		SDL_DestroyRenderer(data->renderer);
	if (data->window)
		SDL_DestroyWindow(data->window);
	SDL_Quit();
	return (type);
}

static void	sdl_events_hook(t_gui *data)
{
	if (data->event.key.keysym.sym == SDLK_ESCAPE)
		data->running = SDL_TRUE;
}

void	visual(t_gui *data)
{
	int			i;

	i = 0;
	while (i < ARN_SIZE)
	{
		if (i % CHAR_WIDTH == 0)
			data->arn_pixels[i++] = 0xFF00;
		else if (i / ARN_WIDTH % CHAR_HEIGHT == 0)
			data->arn_pixels[i++] = 0xFF00;
		else
			data->arn_pixels[i++] = 255;
	}
}

static int	create_corewar_visual(t_gui *data)
{
	int			test;
	SDL_Rect	arena;
	int			i;

	arena.x = 16;
	arena.y = 80;
	arena.w = ARN_WIDTH;
	arena.h = 21;
	i = 0;
	if (!SDL_LockTexture(data->texture, NULL, (void**)&data->pixels
			, &test))
	{
		SDL_UnlockTexture(data->texture);
		SDL_RenderCopy(data->renderer, data->texture, NULL, NULL);
		while (i < 64)
		{
			arena.y = i++ * arena.h + 80;
			SDL_RenderCopy(data->renderer, data->arn_texture, NULL, &arena);
		}
		while (SDL_PollEvent(&data->event))
			sdl_events_hook(data);
		SDL_RenderPresent(data->renderer);
	}
	return (0);
}

static int	init_font(t_gui *data)
{
	SDL_Color	color = {255, 255, 255, 0};
	if (TTF_Init() < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize TTF: %s"
				, SDL_GetError());
		return (1);
	}
			printf("Yo\n");
	if (!(data->font = TTF_OpenFont("/Library/Fonts/Tahoma.ttf", 15)))
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create font: %s"
				, SDL_GetError());
		return (1);
	}
			printf("Yo\n");
	if (!(data->text = TTF_RenderText_Solid(data->font, "12 34 56 78 90 12 34 56 78 90 12 34 56 78 90 12 34 56 78 90 12 34 56 78 90 12 34 56 78 90 12 34 12 34 56 78 90 12 34 56 78 90 12 34 56 78 90 12 34 56 78 90 12 34 56 78 90 12 34 56 78 90 12 34", color)))
		return (1);
			printf("Yo\n");
	if (!(data->arn_texture = SDL_CreateTextureFromSurface(data->renderer, data->text)))
		return (1);
			printf("Yo\n");
	return (0);
}

static int	init_texture(t_gui *data)
{
	if (!(data->texture = SDL_CreateTexture(data->renderer
					, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING
					, WIDTH, HEIGHT)))
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture: %s"
				, SDL_GetError());
		return (1);
	}
//	if (!(data->arn_texture = SDL_CreateTexture(data->renderer
//					, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING
//					, ARN_WIDTH, ARN_HEIGHT)))
//	{
//		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture: %s"
//				, SDL_GetError());
//		return (1);
//	}
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
	if (!(data->window = SDL_CreateWindow("Corewar"
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
		return (leave_sdl(data, 1));
	while (!data->running)
		create_corewar_visual(data);
	return (leave_sdl(data, 0));
}
