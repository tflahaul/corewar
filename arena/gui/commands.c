/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:27:54 by roduquen          #+#    #+#             */
/*   Updated: 2019/09/01 15:00:05 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui.h>

static void	sdl_events_hook_mouse(t_gui *data)
{
	if (data->event.type == SDL_MOUSEBUTTONDOWN && data->event.button.x >= START_X)
	{
		if (data->event.button.y >= START_QUIT && data->event.button.y <= HEIGHT_QUIT)
		{
			if (data->event.button.x <= WIDTH_QUIT)
			{
				leave_sdl(data, EXIT_SUCCESS);
				return ;
			}
		}
		if (data->event.button.y >= START_PAUSE && data->event.button.y <= HEIGHT_PAUSE)
			if (data->event.button.x <= WIDTH_PAUSE)
				data->pause = ~data->pause;
		if (data->event.button.y >= START_UP && data->event.button.y <= HEIGHT_UP)
			if (data->event.button.x <= WIDTH_UP)
				data->speed++;
		if (data->event.button.y >= START_DOWN && data->event.button.y <= HEIGHT_DOWN)
			if (data->event.button.x <= WIDTH_DOWN)
				data->speed--;
		if (data->event.button.y >= START_MAX && data->event.button.y <= HEIGHT_MAX)
			if (data->event.button.x <= WIDTH_MAX)
				data->speed = 100;
		if (data->event.button.y >= START_MIN && data->event.button.y <= HEIGHT_MIN)
			if (data->event.button.x <= WIDTH_MIN)
				data->speed = 1;
	}
}

void		sdl_events_hook(t_gui *data)
{
	if (data->event.type == SDL_KEYDOWN && !data->event.key.repeat)
	{
		if (data->event.key.keysym.sym == SDLK_ESCAPE)
		{
			leave_sdl(data, EXIT_SUCCESS);
			return ;
		}
		if (data->event.key.keysym.sym == SDLK_SPACE)
			data->pause = ~data->pause;
		if (data->event.key.keysym.sym == SDLK_EQUALS)
			data->speed = 100;
		if (data->event.key.keysym.sym == SDLK_KP_PLUS)
			data->speed++;
		if (data->event.key.keysym.sym == SDLK_MINUS)
			data->speed = 1;
		if (data->event.key.keysym.sym == SDLK_KP_MINUS)
			data->speed--;
	}
	sdl_events_hook_mouse(data);
	if (data->speed < 1)
		data->speed = 1;
	if (data->speed > 100)
		data->speed = 100;
}
