/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <roduquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:54:04 by roduquen          #+#    #+#             */
/*   Updated: 2019/09/01 20:45:11 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui.h>
#include <arena.h>
#include <arena_errors.h>
#include <arena_process.h>

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

static void	add_text_to_texture(t_gui *data)
{
	SDL_Rect	arena;
	int			i;

	i = 0;
	while (i < 2560 * 1440)
	{
		data->pixels[i] = ((unsigned int*)data->bmp->pixels)[i];
		i++;
	}
	SDL_RenderCopy(data->renderer, data->texture, NULL, NULL);
	i = 0;
	while (i < 4096)
	{
		arena.w = CHAR_WIDTH;
		arena.h = CHAR_HEIGHT;
		arena.x = data->pos[i][0];
		arena.y = data->pos[i][1];
		SDL_RenderCopy(data->renderer, data->byte_s[(int)g_arena.arena[i]]
				[(int)g_arena.arena_p[i]], NULL, &arena);
		i++;
	}
}

int			create_corewar_visual(t_gui *data)
{
	int			test;

	if (!SDL_LockTexture(data->texture, NULL, (void**)&data->pixels, &test))
	{
		SDL_UnlockTexture(data->texture);
		add_text_to_texture(data);
		SDL_RenderPresent(data->renderer);
	}
	frame_calculator(SDL_GetTicks());
	while (SDL_PollEvent(&data->event))
		sdl_events_hook(data);
	while (!data->pause)
	{
		SDL_PollEvent(&data->event);
		sdl_events_hook(data);
	}
	return (EXIT_SUCCESS);
}
