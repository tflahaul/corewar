/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <roduquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:54:04 by roduquen          #+#    #+#             */
/*   Updated: 2019/09/02 13:35:39 by roduquen         ###   ########.fr       */
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

static int	add_text_for_ui(t_gui *data, int cycle)
{
	SDL_Rect	pos;
	SDL_Surface	*tmp;
	SDL_Texture	*tmp_s;
	char		*str;

	pos.x = 2140;
	pos.y = 560;
	if (data->pause)
	{
		SDL_QueryTexture(data->ui_s[0], NULL, NULL, &pos.w, &pos.h);
		SDL_RenderCopy(data->renderer, data->ui_s[0], NULL, &pos);
	}
	else
	{
		SDL_QueryTexture(data->ui_s[1], NULL, NULL, &pos.w, &pos.h);
		SDL_RenderCopy(data->renderer, data->ui_s[1], NULL, &pos);
	}
	pos.y = 465;
	str = (char*)malloc(sizeof(char) * 4096);
	sprintf(str, "%d", cycle);
	if (!(tmp = TTF_RenderText_Blended(data->font[1], str, data->color[0])))
		return (EXIT_FAILURE);
	if (!(tmp_s = SDL_CreateTextureFromSurface(data->renderer, tmp)))
		return (EXIT_FAILURE);
	SDL_QueryTexture(tmp_s, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(data->renderer, tmp_s, NULL, &pos);
	SDL_FreeSurface(tmp);
	SDL_DestroyTexture(tmp_s);
	pos.y = 655;
	sprintf(str, "%d", data->speed * 60);
	if (!(tmp = TTF_RenderText_Blended(data->font[1], str, data->color[0])))
		return (EXIT_FAILURE);
	if (!(tmp_s = SDL_CreateTextureFromSurface(data->renderer, tmp)))
		return (EXIT_FAILURE);
	SDL_QueryTexture(tmp_s, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(data->renderer, tmp_s, NULL, &pos);
	SDL_FreeSurface(tmp);
	SDL_DestroyTexture(tmp_s);
	free(str);
	return (EXIT_SUCCESS);
}


int			create_corewar_visual(t_gui *data, int cycle)
{
	int			test;

	while (SDL_PollEvent(&data->event))
		sdl_events_hook(data);
	if (!(cycle % data->speed))
	{
		if (!SDL_LockTexture(data->texture, NULL, (void**)&data->pixels, &test))
		{
			SDL_UnlockTexture(data->texture);
			add_text_to_texture(data);
			if (add_text_for_ui(data, cycle) == EXIT_FAILURE)
				return (leave_sdl(data, EXIT_FAILURE));
			SDL_RenderPresent(data->renderer);
		}
	}
	frame_calculator(SDL_GetTicks());
	while (!data->pause)
	{
		while (SDL_PollEvent(&data->event))
			sdl_events_pause(data);
	}
	return (EXIT_SUCCESS);
}
