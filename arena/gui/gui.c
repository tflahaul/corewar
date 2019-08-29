/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <roduquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:54:04 by roduquen          #+#    #+#             */
/*   Updated: 2019/08/29 16:14:08 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>

static void		string_position(t_gui *data)
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

static void	init_color_and_count(SDL_Color color[5], int count[4])
{
	color[0].r = 185;
	color[0].g = 185;
	color[0].b = 185;
	color[0].a = 0;
	color[1].r = 225;
	color[1].g = 20;
	color[1].b = 20;
	color[1].a = 0;
	color[2].r = 20;
	color[2].g = 20;
	color[2].b = 225;
	color[2].a = 0;
	color[3].r = 20;
	color[3].g = 225;
	color[3].b = 20;
	color[3].a = 0;
	color[4].r = 200;
	color[4].g = 84;
	color[4].b = 179;
	color[4].a = 0;
	count[3] = -1;
}

static int	create_every_strings(t_gui *data)
{
	int			count[4];
	static char	*base = "0123456789ABCDEF";
	char		byte[3];
	SDL_Color	color[5];

	init_color_and_count(color, count);
	byte[2]= 0;
	while (++count[3] < 5)
	{
		count[0] = -1;
		count[2] = 0;
		while (++count[0] < 16)
		{
			count[1] = -1;
			while (++count[1] < 16)
			{
				byte[0] = base[count[0]];
				byte[1] = base[count[1]];
				data->byte[count[2]][count[3]] = TTF_RenderText_Blended(
						data->font, byte, color[count[3]]);
				if (!data->byte[count[2]][count[3]])
				{
					SDL_LogError(SDL_LOG_CATEGORY_APPLICATION
							, "Couldn't load strings: %s", SDL_GetError());
					return (EXIT_FAILURE);
				}
				if (!(data->byte_s[count[2]][count[3]] = SDL_CreateTextureFromSurface(data->renderer, data->byte[count[2]][count[3]])))
				{
					SDL_LogError(SDL_LOG_CATEGORY_APPLICATION
							, "Couldn't create strings: %s", SDL_GetError());
					return (EXIT_FAILURE);
				}
				count[2]++;
			}
		}
	}
	return (EXIT_SUCCESS);
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
	data->running = SDL_TRUE;
	return (type);
}

static void	sdl_events_hook(t_gui *data)
{
	if (data->event.type == SDL_KEYDOWN && data->event.key.keysym.sym == SDLK_ESCAPE)
		leave_sdl(data, EXIT_SUCCESS);
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

void		frame_calculator(unsigned int actual)
{
	static unsigned int	frame = 0;
	static unsigned int	time = 0;

	if (actual - time > 1000)
	{
		printf("FPS : ");
		printf("%d\n", frame);
		frame = 0;
		time = actual;
	}
	frame++;
}

int			create_corewar_visual(t_gui *data)
{
	int			i;
	int			test;
	SDL_Rect	arena;

	i = 0;
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
		while (i < 4096)
		{
			arena.w = CHAR_WIDTH * 2;
			arena.h = CHAR_HEIGHT;
			arena.x = data->pos[i][0];
			arena.y = data->pos[i][1];
			SDL_RenderCopy(data->renderer, data->byte_s[(int)g_arena.arena[i]][(int)g_arena.arena_p[i]], NULL, &arena);
			i++;
		}
		SDL_RenderPresent(data->renderer);
	}
	frame_calculator(SDL_GetTicks());
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
	if (create_every_strings(data))
		return (EXIT_FAILURE);
	string_position(data);
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
	return (EXIT_SUCCESS);
}
