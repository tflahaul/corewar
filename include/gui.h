/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:02:53 by roduquen          #+#    #+#             */
/*   Updated: 2019/09/01 14:44:37 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# define	ARN_HEIGHT			(1344)
# define	ARN_WIDTH			(1728)
# define	ARN_SIZE			(ARN_WIDTH * ARN_HEIGHT)
# define	CHAR_HEIGHT			(21)
# define	CHAR_WIDTH			(18)
# define	HEIGHT				(1440)
# define	WIDTH				(2560)
# define	SIZE				(WIDTH * HEIGHT)

# define	START_X				(2143)
# define	START_QUIT			(95)
# define	HEIGHT_QUIT			(47 + START_QUIT)
# define	WIDTH_QUIT			(101 + START_X)
# define	START_PAUSE			(147)
# define	HEIGHT_PAUSE		(37 + START_PAUSE)
# define	WIDTH_PAUSE			(140 + START_X)
# define	START_UP			(195)
# define	HEIGHT_UP			(47 + START_UP)
# define	WIDTH_UP			(214 + START_X)
# define	START_DOWN			(245)
# define	HEIGHT_DOWN			(47 + START_DOWN)
# define	WIDTH_DOWN			(278 + START_X)
# define	START_MAX			(295)
# define	HEIGHT_MAX			(47 + START_MAX)
# define	WIDTH_MAX			(253 + START_X)
# define	START_MIN			(345)
# define	HEIGHT_MIN			(47 + START_MIN)
# define	WIDTH_MIN			(240 + START_X)

# include <SDL.h>
# include <SDL_ttf.h>

typedef struct s_gui			t_gui;

struct							s_gui
{
	SDL_Renderer				*renderer;
	SDL_Window					*window;
	SDL_Texture					*texture;
	TTF_Font					*font[2];
	SDL_Surface					*byte[256][5];
	SDL_Texture					*byte_s[256][5];
	SDL_Surface					*bmp;
	uint32_t					*pixels;
	SDL_Color					color[5];
	SDL_Event					event;
	SDL_bool					running;
	int							text_w;
	int							text_h;
	int							pos[4096][2];
	int							speed;
	char						pause;
};

int								gui(t_gui *data);

/*
**	Console messages
*/

void							ft_print_winner(void);
void							ft_introduce_contestants(void);
int								create_corewar_visual(t_gui *data);
int								create_every_strings(t_gui *data, char *base);
int								leave_sdl(t_gui *data, int type);
void							sdl_events_hook(t_gui *data);

#endif
