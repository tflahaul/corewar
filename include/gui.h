/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:02:53 by roduquen          #+#    #+#             */
/*   Updated: 2019/09/01 17:49:50 by roduquen         ###   ########.fr       */
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

# define	S_X				(2143)
# define	S_QUIT			(95)
# define	H_QUIT			(47 + S_QUIT)
# define	W_QUIT			(101 + S_X)
# define	S_PAUSE			(147)
# define	H_PAUSE		(37 + S_PAUSE)
# define	W_PAUSE			(140 + S_X)
# define	S_UP			(195)
# define	H_UP			(47 + S_UP)
# define	W_UP			(214 + S_X)
# define	S_DOWN			(245)
# define	H_DOWN			(47 + S_DOWN)
# define	W_DOWN			(278 + S_X)
# define	S_MAX			(295)
# define	H_MAX			(47 + S_MAX)
# define	W_MAX			(253 + S_X)
# define	S_MIN			(345)
# define	H_MIN			(47 + S_MIN)
# define	W_MIN			(240 + S_X)

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
int								sdl_events_hook(t_gui *data);

#endif
