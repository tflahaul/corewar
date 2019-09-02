/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:27:54 by roduquen          #+#    #+#             */
/*   Updated: 2019/09/02 13:34:42 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui.h>

static int	sdl_events_hook_mouse(t_gui *data)
{
	if (data->event.type == SDL_MOUSEBUTTONDOWN && data->event.button.x >= S_X)
	{
		if (data->event.button.y >= S_QUIT && data->event.button.y <= H_QUIT)
			if (data->event.button.x <= W_QUIT)
				return (leave_sdl(data, EXIT_SUCCESS));
		if (data->event.button.y >= S_PAUSE && data->event.button.y <= H_PAUSE)
			if (data->event.button.x <= W_PAUSE)
				data->pause = ~data->pause;
		if (data->event.button.y >= S_UP && data->event.button.y <= H_UP)
			if (data->event.button.x <= W_UP)
				data->speed++;
		if (data->event.button.y >= S_DOWN && data->event.button.y <= H_DOWN)
			if (data->event.button.x <= W_DOWN)
				data->speed--;
		if (data->event.button.y >= S_MAX && data->event.button.y <= H_MAX)
			if (data->event.button.x <= W_MAX)
				data->speed = 100;
		if (data->event.button.y >= S_MIN && data->event.button.y <= H_MIN)
			if (data->event.button.x <= W_MIN)
				data->speed = 1;
	}
	return (0);
}

int			sdl_events_pause(t_gui *data)
{
	if (data->event.type == SDL_MOUSEBUTTONDOWN && data->event.button.x >= S_X)
	{
		if (data->event.button.y >= S_QUIT && data->event.button.y <= H_QUIT)
			if (data->event.button.x <= W_QUIT)
				return (leave_sdl(data, EXIT_SUCCESS));
		if (data->event.button.y >= S_PAUSE && data->event.button.y <= H_PAUSE)
			if (data->event.button.x <= W_PAUSE)
				data->pause = ~data->pause;
	}
	if (data->event.type == SDL_KEYDOWN && !data->event.key.repeat)
	{
		if (data->event.key.keysym.sym == SDLK_ESCAPE)
			return (leave_sdl(data, EXIT_SUCCESS));
		if (data->event.key.keysym.sym == SDLK_SPACE)
			data->pause = ~data->pause;
	}
	return (EXIT_SUCCESS);
}

int			sdl_events_hook(t_gui *data)
{
	if (data->event.type == SDL_KEYDOWN && !data->event.key.repeat)
	{
		if (data->event.key.keysym.sym == SDLK_ESCAPE)
			return (leave_sdl(data, EXIT_SUCCESS));
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
	return (0);
}
