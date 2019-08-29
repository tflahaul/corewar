/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <roduquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:54:04 by roduquen          #+#    #+#             */
/*   Updated: 2019/08/29 14:10:23 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>

static int	create_every_strings(t_gui *gui)
{

}

static char	base_hexa(int c)
{
	static char	*base = "0123456789ABCDEF";

	return (base[c]);
}

static void	translate_arena_to_string(t_gui *data)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	k = 0;
	j = 0;
	while (i < MEM_SIZE)
	{
		data->string[k][j++] = base_hexa(g_arena.arena[i] / 16);
		data->string[k][j++] = base_hexa(g_arena.arena[i] % 16);
		if (j < 191)
			data->string[k][j++] = ' ';
		else
		{
			data->string[k][j] = 0;
			j = 0;
		}
		i++;
		if (i % 64 == 0)
			k++;
	}
}

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
	if (data->event.type == SDL_KEYDOWN && data->event.key.keysym.sym == SDLK_ESCAPE)
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
	int			i;
	int			test;
	SDL_Rect	arena;
	SDL_Color	color = {255, 255, 255, 0};
	static int	antilag = 0;

	arena.x = 16;
	arena.y = 80;
	i = 0;
	translate_arena_to_string(data);
	if (antilag == 0)
	{
		if (!SDL_LockTexture(data->texture, NULL, (void**)&data->pixels, &test))
		{
			SDL_UnlockTexture(data->texture);
			while (i < 2560 * 1440)
			{
				data->pixels[i] = ((unsigned int*)data->bmp->pixels)[i];
				i++;
			}
			i = 0;
			SDL_RenderCopy(data->renderer, data->texture, NULL, NULL);
			while (i < 64)
			{
				if (i % 4 == 0)
					color.r = 0;
				else if (i % 4 == 1)
				{
					color.r = 255;
					color.g = 0;
				}
				else if (i % 4 == 2)
				{
					color.g = 255;
					color.b = 0;
				}
				else
					color.b = 255;
				if (!(data->text = TTF_RenderText_Blended(data->font, data->string[i], color)))
					return (1);
				if (!(data->arn_texture = SDL_CreateTextureFromSurface(data->renderer, data->text)))
					return (1);
				SDL_QueryTexture(data->arn_texture, NULL, NULL, &data->text_w, &data->text_h);
				arena.w = data->text_w;
				arena.h = data->text_h;
				printf("w = %u, h = %u\n", data->text_w, data->text_h);
				arena.y = i++ * arena.h + 80;
				SDL_RenderCopy(data->renderer, data->arn_texture, NULL, &arena);
			}
			SDL_RenderPresent(data->renderer);
		}
	}
	antilag++;
	while (SDL_PollEvent(&data->event))
		sdl_events_hook(data);
	return (EXIT_SUCCESS);
}

static int	init_font(t_gui *data)
{
	if (TTF_Init() < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize TTF: %s"
				, SDL_GetError());
		return (EXIT_FAILURE);
	}
	if (!(data->font = TTF_OpenFont("arena/gui/monofonto.ttf", 17)))
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create font: %s"
				, SDL_GetError());
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
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
	if (!(data->bmp = SDL_LoadBMP("arena/gui/graphic.bmp")))
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create bmp: %s"
				, SDL_GetError());
		return (EXIT_FAILURE);
	}
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
	while (!data->running)
		create_corewar_visual(data);
	return (leave_sdl(data, EXIT_SUCCESS));
}
